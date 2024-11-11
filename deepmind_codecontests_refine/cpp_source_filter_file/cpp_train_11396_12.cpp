#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
struct tree {
  int l, r;
  bool f[30];
};
long long ans[maxn];
int n, m;
tree tr[maxn * 4];
long long q[maxn];
int lll[maxn], rr[maxn];
int dp[maxn][30];
void build(int root, int l, int r) {
  tr[root].l = l;
  tr[root].r = r;
  for (int i = 0; i < 30; i++) {
    tr[root].f[i] = 0;
  }
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  build(root * 2, l, mid);
  build(root * 2 + 1, mid + 1, r);
}
void update(int root, int l, int r, int ii) {
  if (tr[root].f[ii]) return;
  if (tr[root].l >= l && tr[root].r <= r) {
    tr[root].f[ii] = 1;
    return;
  }
  if (tr[root].r < l || tr[root].l > r) return;
  int mid = tr[root].l + tr[root].r >> 1;
  if (mid < l)
    update(root * 2 + 1, l, r, ii);
  else if (mid >= r)
    update(root * 2, l, r, ii);
  else {
    update(root * 2 + 1, l, r, ii);
    update(root * 2, l, r, ii);
  }
  tr[root].f[ii] = tr[root * 2].f[ii] & tr[root * 2 + 1].f[ii];
}
long long res;
void query(int root, int idx) {
  int mid = tr[root].l + tr[root].r >> 1;
  for (int i = 0; i < 30; i++) {
    if (tr[root].f[i]) {
      res |= 1 << i;
    }
  }
  if (tr[root].l == tr[root].r) return;
  if (mid >= idx)
    query(root * 2, idx);
  else
    query(root * 2 + 1, idx);
}
int main() {
  n = read(), m = read();
  build(1, 1, n);
  int k = 1;
  while (k <= m) {
    int l = read(), r = read();
    long long x = read();
    lll[k] = l, rr[k] = r;
    q[k] = x;
    int i = 0;
    while (x) {
      if (x % 2) {
        update(1, l, r, i);
      }
      x >>= 1;
      i++;
    }
    k++;
  }
  for (int i = 1; i <= n; i++) {
    res = 0;
    query(1, i);
    long long h = 0;
    ans[i] = res;
    while (h < 30) {
      dp[i][h] = dp[i - 1][h] + (res & (1 << h));
      h++;
    }
  }
  int f = 1;
  for (int i = 1; i <= m; i++) {
    long long h = 0;
    while (h < 30) {
      if ((q[i] & (1 << h)) == 0) {
        if (dp[rr[i]][h] - dp[lll[i] - 1][h] == rr[i] - lll[i] + 1) {
          f = 0;
          break;
        }
      }
      h++;
    }
    if (!f) break;
  }
  if (f) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
  } else {
    cout << "NO\n";
  }
}
