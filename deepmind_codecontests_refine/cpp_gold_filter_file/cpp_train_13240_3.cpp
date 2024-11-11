#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
const int r = 1 << 18;
int treemin[2 * r];
int tmax[2 * r];
int tadd[2 * r];
int t0[maxN];
int t[maxN];
int N, shift0;
int last_idx;
int get_min_pos(int a, int b) {
  a += r;
  b += r;
  int res = 0;
  while (a < b) {
    if (a & 1) {
      if (t[res] > t[treemin[a]]) res = treemin[a];
      a /= 2;
      a++;
    } else
      a /= 2;
    if (b & 1)
      b /= 2;
    else {
      if (t[res] > t[treemin[b]]) res = treemin[b];
      b /= 2;
      b--;
    }
  }
  if (a == b) {
    if (t[res] > t[treemin[a]]) res = treemin[a];
  }
  return res;
}
void add(int za, int zb, int val, int ta = 0, int tb = r - 1, int x = 1) {
  if (za <= ta && tb <= zb) {
    tadd[x] += val;
    tmax[x] += val;
    return;
  }
  int avg = (ta + tb) / 2;
  if (za <= avg) add(za, zb, val, ta, avg, 2 * x);
  if (avg < zb) add(za, zb, val, avg + 1, tb, 2 * x + 1);
  tmax[x] = tadd[x] + max(tmax[2 * x], tmax[2 * x + 1]);
}
int get_max(int za, int zb, int ta = 0, int tb = r - 1, int x = 1) {
  if (za <= ta && tb <= zb) return tmax[x];
  int avg = (ta + tb) / 2, res = -1e9;
  if (za <= avg) res = max(res, get_max(za, zb, ta, avg, 2 * x));
  if (avg < zb) res = max(res, get_max(za, zb, avg + 1, tb, 2 * x + 1));
  return res + tadd[x];
}
int b0[maxN];
int b1[maxN];
void create_dep(int a, int b, int dp) {
  int best = get_min_pos(a, b);
  b0[best] = a;
  b1[best] = b;
  tmax[best + r] = dp;
  if (a != best) create_dep(a, best - 1, dp + 1);
  if (b != best) create_dep(best + 1, b, dp + 1);
}
void init() {
  last_idx = N;
  for (int i = 1; i <= N; ++i) {
    treemin[i + r] = i;
  }
  for (int i = r - 1; i > 0; --i) {
    treemin[i] = treemin[2 * i + 1];
    if (t[treemin[i]] > t[treemin[2 * i]]) treemin[i] = treemin[2 * i];
  }
  create_dep(1, N, 1);
  for (int i = r - 1; i > 0; --i) {
    tmax[i] = max(tmax[2 * i], tmax[2 * i + 1]);
  }
}
void move1() {
  int idx = last_idx--;
  if (b0[idx] != idx) add(b0[idx], idx - 1, -1);
  int dep0 = get_max(idx, idx);
  int dep1 = 2;
  if (b1[idx] != N) dep1 = get_max(b1[idx] + 1, b1[idx] + 1) + 1;
  add(idx, idx, dep1 - dep0);
  if (b1[idx] != idx) add(idx + 1, b1[idx], 1);
}
void print_deps() {
  for (int i = 0; i <= N; ++i) {
    printf("%d ", get_max(i, i));
  }
  puts("");
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", t0 + i);
    if (t0[i] == 1) shift0 = N - i;
  }
  for (int i = 0; i < N; ++i) t[1 + (i + shift0) % N] = t0[i];
  t[0] = 1e9;
  init();
  int bestshift = 0, bestdep = tmax[1];
  for (int i = 0; i < N - 1; ++i) {
    move1();
    if (tmax[1] < bestdep) {
      bestdep = tmax[1];
      bestshift = i + 1;
    }
  }
  printf("%d %d\n", bestdep, (N - (bestshift + shift0) % N) % N);
}
