#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(const T &a) {
  return a * a;
}
const int MAXN = 2e5 + 100;
char s[MAXN];
int t[4 * MAXN][26], p[4 * MAXN], cnt[26], n, q, l, r, k;
void add(int *to, int *l, int *r) {
  for (int i = 0; i < (int)26; i++) to[i] += l[i] + r[i];
}
void add(int *to, int *from) {
  for (int i = 0; i < (int)26; i++) to[i] += from[i];
}
void build(int vl, int vr, int v) {
  p[v] = -1;
  if (vl + 1 == vr) {
    t[v][s[vl] - 'a'] = 1;
    return;
  }
  int vm = (vl + vr) / 2;
  build(vl, vm, 2 * v);
  build(vm, vr, 2 * v + 1);
  add(t[v], t[2 * v], t[2 * v + 1]);
}
void push(int v, int vl, int vr) {
  if (p[v] == -1) return;
  p[2 * v] = p[2 * v + 1] = p[v];
  int vm = (vl + vr) / 2;
  for (int i = 0; i < (int)26; i++) t[2 * v][i] = t[2 * v + 1][i] = 0;
  t[2 * v][p[v]] = vm - vl;
  t[2 * v + 1][p[v]] = vr - vm;
  p[v] = -1;
}
void Get(int vl, int vr, int l, int r, int v) {
  if (vl >= l && vr <= r) {
    add(cnt, t[v]);
    return;
  }
  if (vl >= r || vr <= l) return;
  push(v, vl, vr);
  int vm = (vl + vr) / 2;
  Get(vl, vm, l, r, 2 * v);
  Get(vm, vr, l, r, 2 * v + 1);
}
void change(int vl, int vr, int l, int r, int x, int v) {
  if (vl >= l && vr <= r) {
    p[v] = x;
    for (int i = 0; i < (int)26; i++) t[v][i] = 0;
    t[v][x] = vr - vl;
    return;
  }
  if (vl >= r || vr <= l) return;
  push(v, vl, vr);
  int vm = (vl + vr) / 2;
  change(vl, vm, l, r, x, 2 * v);
  change(vm, vr, l, r, x, 2 * v + 1);
  for (int i = 0; i < (int)26; i++) t[v][i] = 0;
  add(t[v], t[2 * v], t[2 * v + 1]);
}
void print(int vl, int vr, int v) {
  if (vl + 1 == vr) {
    for (int i = 0; i < (int)26; i++)
      if (t[v][i]) printf("%c", 'a' + i);
    return;
  }
  push(v, vl, vr);
  int vm = (vl + vr) / 2;
  print(vl, vm, 2 * v);
  print(vm, vr, 2 * v + 1);
}
int main() {
  scanf("%d%d\n", &n, &q);
  gets(s);
  build(0, n, 1);
  for (int qweretr = 0; qweretr < (int)q; qweretr++) {
    scanf("%d%d%d", &l, &r, &k);
    for (int i = 0; i < (int)26; i++) cnt[i] = 0;
    Get(0, n, l - 1, r, 1);
    if (k) {
      int pos = l - 1;
      for (int i = 0; i < (int)26; i++)
        change(0, n, pos, pos + cnt[i], i, 1), pos += cnt[i];
    } else {
      int pos = l - 1;
      for (int i = 26 - 1; i >= 0; i--)
        change(0, n, pos, pos + cnt[i], i, 1), pos += cnt[i];
    }
  }
  print(0, n, 1);
}
