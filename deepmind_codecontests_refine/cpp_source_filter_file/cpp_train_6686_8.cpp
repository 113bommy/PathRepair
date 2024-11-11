#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXNN = 55;
const int MAXMM = 10;
int nn, mm, kk;
long long G[MAXNN][MAXMM];
long long dp[MAXNN][MAXMM];
long long sum[MAXNN][MAXMM];
struct {
  long long w;
  long long tag;
} tree[10000 * 4 + 5];
void build(int l, int r, int rt, int day) {
  tree[rt].tag = 0;
  if (l == r) {
    tree[rt].w = dp[day][l];
    return;
  }
  int m = (l + r) / 2;
  build(l, m, rt * 2, day);
  build(m + 1, r, rt * 2 + 1, day);
  tree[rt].w = max(tree[rt * 2].w, tree[rt * 2 + 1].w);
}
void push_down(int l, int r, int rt) {
  if (tree[rt].tag == 0) {
    return;
  }
  int m = (l + r) / 2;
  tree[rt * 2].w += tree[rt].tag;
  tree[rt * 2].tag += tree[rt].tag;
  tree[rt * 2 + 1].w += tree[rt].tag;
  tree[rt * 2 + 1].tag += tree[rt].tag;
  tree[rt].tag = 0;
}
void _update(int L, int R, int l, int r, int rt, long long add) {
  if (l >= L && r <= R) {
    tree[rt].w += add;
    tree[rt].tag += add;
    return;
  }
  if (tree[rt].tag) {
    push_down(l, r, rt);
  }
  int m = (l + r) / 2;
  if (L <= m) {
    _update(L, R, l, m, rt * 2, add);
  }
  if (R > m) {
    _update(L, R, m + 1, r, rt * 2 + 1, add);
  }
  tree[rt].w = max(tree[rt * 2].w, tree[rt * 2 + 1].w);
}
long long query(int L, int R, int l, int r, int rt) {
  if (l >= L && r <= R) {
    return tree[rt].w;
  }
  if (tree[rt].tag) {
    push_down(l, r, rt);
  }
  long long ans = 0;
  int m = (l + r) / 2;
  if (L <= m) {
    ans = max(ans, query(L, R, l, m, rt * 2));
  }
  if (R > m) {
    ans = max(ans, query(L, R, m + 1, r, rt * 2 + 1));
  }
  return ans;
}
void update(int L, int R, long long x) { _update(L, R, 1, mm - kk + 1, 1, x); }
long long query(int L, int R) { return query(L, R, 1, mm - kk + 1, 1); }
void print_seg_tree() {
  for (int i = 1; i <= mm - kk + 1; ++i) {
    printf("%4lld", query(i, i));
  }
  printf("\n");
}
int main() {
  scanf("%d%d%d", &nn, &mm, &kk);
  for (int i = 1; i <= nn; ++i) {
    for (int j = 1; j <= mm; ++j) {
      scanf("%lld", &G[i][j]);
      sum[i][j] = sum[i][j - 1] + G[i][j];
    }
  }
  for (int i = 1; i <= mm - kk + 1; ++i) {
    dp[1][i] = (sum[1][i + kk - 1] + sum[2][i + kk - 1]) -
               (sum[1][i - 1] + sum[2][i - 1]);
  }
  build(1, mm - kk + 1, 1, 1);
  for (int i = 2; i <= nn; ++i) {
    for (int j = 1; j <= kk; ++j) {
      update(1, j, -(sum[i][j] - sum[i][j - 1]));
    }
    dp[i][1] = query(1, mm - kk + 1) + (sum[i][kk] - sum[i][0]) +
               (sum[i + 1][kk] - sum[i + 1][0]);
    for (int j = 2; j <= mm - kk + 1; ++j) {
      update(max(1, j - kk), j - 1, sum[i][j - 1] - sum[i][j - 2]);
      update(j, j + kk - 1, -(sum[i][j + kk - 1] - sum[i][j + kk - 2]));
      dp[i][j] = query(1, mm - kk + 1) +
                 (sum[i][j + kk - 1] + sum[i + 1][j + kk - 1]) -
                 (sum[i][j - 1] + sum[i + 1][j - 1]);
    }
    build(1, mm - kk + 1, 1, i);
  }
  printf("%lld\n", query(1, mm - kk + 1));
  return 0;
}
