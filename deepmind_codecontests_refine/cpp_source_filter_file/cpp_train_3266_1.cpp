#include <bits/stdc++.h>
using namespace std;
int n, m;
inline long long fast_pow(long long x, long long k) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans = ans * x % 1000000007;
    x = x * x % 1000000007;
    k >>= 1;
  }
  return ans;
}
inline long long inv(long long x) { return fast_pow(x, 1000000007 - 2); }
long long fact[100000 + 5];
long long invfact[100000 + 5];
void ini_fact(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % 1000000007;
  invfact[n] = inv(fact[n]);
  for (int i = n - 1; i >= 0; i--)
    invfact[i] = invfact[i + 1] * (i + 1) % 1000000007;
}
inline long long C(int n, int m) {
  return fact[n] * invfact[n - m] % 1000000007 * invfact[m] % 1000000007;
}
long long sump[5 + 5][100000 + 5];
void ini_pow(int n, int k) {
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      sump[i][j] = (sump[i][j - 1] + fast_pow(j, i)) % 1000000007;
    }
  }
}
inline long long get_sump(int k, int l, int r) {
  return (sump[k][r] - sump[k][l - 1] + 1000000007) % 1000000007;
}
struct segment_tree {
  struct node {
    int l;
    int r;
    long long val;
    long long mark;
  } tree[100000 * 4 + 5];
  int kk;
  void push_up(int pos) {
    tree[pos].val = (tree[pos << 1].val + tree[pos << 1 | 1].val) % 1000000007;
  }
  void build(int l, int r, int *a, int pos) {
    tree[pos].l = l;
    tree[pos].r = r;
    tree[pos].mark = -1;
    if (l == r) {
      tree[pos].val = a[l] * fast_pow(l, kk);
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, a, pos << 1);
    build(mid + 1, r, a, pos << 1 | 1);
    push_up(pos);
  }
  inline void add_mark(int pos, int mark) {
    tree[pos].mark = mark;
    tree[pos].val = mark * get_sump(kk, tree[pos].l, tree[pos].r) % 1000000007;
  }
  void push_down(int pos) {
    if (tree[pos].mark != -1) {
      add_mark(pos << 1, tree[pos].mark);
      add_mark(pos << 1 | 1, tree[pos].mark);
      tree[pos].mark = -1;
    }
  }
  void update(int L, int R, int val, int pos) {
    if (L <= tree[pos].l && R >= tree[pos].r) {
      add_mark(pos, val);
      return;
    }
    push_down(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    if (L <= mid) update(L, R, val, pos << 1);
    if (R > mid) update(L, R, val, pos << 1 | 1);
    push_up(pos);
  }
  long long query(int L, int R, int pos) {
    if (L <= tree[pos].l && R >= tree[pos].r) {
      return tree[pos].val;
    }
    push_down(pos);
    int mid = (tree[pos].l + tree[pos].r) >> 1;
    long long ans = 0;
    if (L <= mid) ans = (ans + query(L, R, pos << 1)) % 1000000007;
    if (R > mid) ans = (ans + query(L, R, pos << 1 | 1)) % 1000000007;
    return ans;
  }
} T[6];
int a[100000 + 5];
int main() {
  char cmd[2];
  int l, r, x, k;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  ini_fact(5);
  ini_pow(n, 5);
  for (int i = 0; i <= 5; i++) {
    T[i].kk = i;
    T[i].build(1, n, a, 1);
  }
  for (int t = 1; t <= m; t++) {
    scanf("%s", cmd);
    if (cmd[0] == '=') {
      scanf("%d %d %d", &l, &r, &x);
      for (int i = 0; i <= 5; i++) T[i].update(l, r, x, 1);
    } else {
      scanf("%d %d %d", &l, &r, &k);
      long long ans = 0;
      for (int j = 0; j <= k; j++) {
        ans += fast_pow(-1, k - j) * C(k, j) % 1000000007 *
               T[j].query(l, r, 1) % 1000000007 * fast_pow(l - 1, k - j) %
               1000000007;
        ans = (ans + 1000000007) % 1000000007;
        ans %= 1000000007;
      }
      printf("%lld\n", ans);
    }
  }
}
