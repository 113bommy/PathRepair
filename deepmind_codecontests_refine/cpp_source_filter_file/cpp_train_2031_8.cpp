#include <bits/stdc++.h>
using namespace std;
void gt(int &a, int b) {
  if (a < b) a = b;
}
string n2s(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}
string getKey(int v, int h) { return n2s(v) + "-" + n2s(h); }
long long dp[1 << 13][13]{0};
int u[105], v[105], a[105], b[105], c[105];
int n, e, q;
bool check_tree(int m, int r) {
  for (int i = 0; i < q; i++) {
    if (a[i] == r && (m & (1 << (b[i]))) && c[i] != r) return false;
    if (b[i] == r && (m & (1 << (a[i]))) && c[i] != r) return false;
  }
  return true;
}
bool check_subtree(int m1, int m2, int r) {
  for (int i = 0; i < q; i++) {
    if ((m1 & (1 << (a[i]))) && (m2 & (1 << (b[i]))) && r != c[i]) return false;
    if ((m2 & (1 << (a[i]))) && (m1 & (1 << (b[i]))) && r != c[i]) return false;
  }
  for (int i = 0; i < e; i++) {
    if ((m1 & (1 << (u[i]))) && (m2 & (1 << (v[i])))) return false;
    if ((m2 & (1 << (u[i]))) && (m1 & (1 << (v[i])))) return false;
  }
  return true;
}
bool check_no_edge(int m, int r) {
  for (int i = 0; i < e; i++) {
    if (r == u[i] && (m & (1 << (v[i])))) return false;
    if (r == v[i] && (m & (1 << (u[i])))) return false;
  }
  return true;
}
int low_bit(int m) {
  for (int x = 0; x < n; x++)
    if ((m & (1 << (x)))) return x;
  return 0;
}
void _dp(int mask, int x) {
  int m = (mask & (~(1 << (x))));
  if ((m & (1 << (0))) && !check_tree(mask, x)) return;
  if (m == 0) {
    dp[mask][x] = 1;
    return;
  }
  int least = low_bit(m);
  for (int m1 = m; m1 > 0; m1 = m & (m1 - 1))
    if ((m1 & (1 << (least)))) {
      int m2 = m ^ m1;
      if (!check_subtree(m1, m2, x)) continue;
      for (int y = 0; y < n; y++)
        if ((m1 & (1 << (y))))
          if (check_no_edge((m1 & (~(1 << (y)))), x)) {
            dp[mask][x] += dp[m1][y] * dp[(m2 | (1 << (x)))][x];
          }
    }
}
int main() {
  cin >> n >> e >> q;
  for (int i = 0; i < e; i++) cin >> u[i] >> v[i], u[i]--, v[i]--;
  for (int i = 0; i < q; i++)
    cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--, c[i]--;
  for (int mask = 0; mask < (1 << (n)); mask++)
    for (int x = 0; x < n; x++)
      if ((mask & (1 << (x)))) _dp(mask, x);
  cout << dp[(1 << (n)) - 1][0];
  return 0;
}
