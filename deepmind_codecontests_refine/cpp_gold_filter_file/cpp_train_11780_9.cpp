#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, q;
int a[maxn], p[maxn], where[maxn];
int lvl[maxn];
int T[20][maxn];
int dest[maxn];
int t[maxn << 2];
void build(int u, int b, int e) {
  if (b == e) return void(t[u] = dest[b]);
  int m = b + e >> 1;
  build(u << 1, b, m);
  build(u << 1 | 1, m + 1, e);
  t[u] = min(t[u << 1], t[u << 1 | 1]);
}
int query(int u, int b, int e, int l, int r) {
  if (b > r or e < l) return INT_MAX;
  if (l <= b and e <= r) return t[u];
  int m = b + e >> 1;
  return min(query(u << 1, b, m, l, r), query(u << 1 | 1, m + 1, e, l, r));
}
int main(int argc, char const *argv[]) {
  cin >> n >> m >> q;
  if (n == 1) {
    string ret(q, '1');
    cout << ret << endl;
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    p[x] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    a[i] = p[a[i]];
  }
  memset(T, -1, sizeof T);
  for (int i = m; i >= 1; i--) {
    lvl[i] = lvl[where[(a[i] % n) + 1]] + 1;
    T[0][i] = where[(a[i] % n) + 1];
    where[a[i]] = i;
  }
  for (int p = 1; p <= 18; p++) {
    for (int i = 1; i <= m; i++) {
      int mid = T[p - 1][i];
      if (mid != -1) {
        T[p][i] = T[p - 1][mid];
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (lvl[i] < n) {
      dest[i] = INT_MAX;
      continue;
    }
    int u = i, d = n - 1;
    for (int p = 18; p >= 0; p--) {
      if (d & (1 << p)) {
        u = T[p][u];
      }
    }
    dest[i] = u;
  }
  build(1, 1, m);
  string ans;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (query(1, 1, m, l, r) <= r) {
      ans += '1';
    } else {
      ans += '0';
    }
  }
  cout << ans << endl;
  return 0;
}
