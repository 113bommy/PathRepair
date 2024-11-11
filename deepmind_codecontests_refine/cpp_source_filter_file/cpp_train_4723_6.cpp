#include <bits/stdc++.h>
using namespace std;
const int bit = 10000;
int n;
int sz[700 + 3];
vector<int> g[700 + 3];
int c[100 + 3];
struct BigInteger {
  int a[60];
  int len;
  void set(int x) {
    len = 0;
    while (x) a[++len] = x % bit, x /= bit;
  }
  void operator*=(const BigInteger &b) {
    memset(c, 0, sizeof c);
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= b.len; j++) {
        c[i + j - 1] += a[i] * b.a[j];
        c[i + j] = c[i + j - 1] / bit;
        c[i + j - 1] %= bit;
      }
    }
    len += b.len;
    while (len > 1 && c[len] == 0) len--;
    while (c[len] >= bit) {
      ++len;
      c[len] = c[len - 1] / bit;
      c[len - 1] %= bit;
    }
    for (int i = 1; i <= len; i++) a[i] = c[i];
  }
  void operator*=(int b) {
    for (int i = 1; i <= len; i++) a[i] *= b;
    for (int i = 1; i <= len; i++) a[i + 1] += a[i] / bit, a[i] %= bit;
    len++;
    while (len > 1 && a[len] == 0) len--;
    while (a[len] >= bit) {
      ++len;
      a[len] = a[len - 1] / bit;
      a[len - 1] %= bit;
    }
  }
  void out() {
    cout << a[len];
    for (int i = len - 1; i >= 1; i--) {
      cout << setfill('0') << setw(4) << a[i];
    }
    cout << "\n";
  }
};
BigInteger dp[700 + 3][700 + 3];
void upd(BigInteger &a, BigInteger b) {
  for (int i = max(a.len, b.len); i >= 1; i--) {
    if (a.a[i] > b.a[i])
      return;
    else if (a.a[i] < b.a[i]) {
      a = b;
      return;
    }
  }
}
void dfs(int u, int pa) {
  sz[u] = 1;
  dp[u][1].set(1);
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == pa) continue;
    dfs(v, u);
    for (int j = sz[u]; j >= 0; j--) {
      for (int k = sz[v]; k >= 0; k--) {
        BigInteger tmp = dp[u][j];
        tmp *= dp[v][k];
        upd(dp[u][j + k], tmp);
      }
    }
    sz[u] += sz[v];
  }
  for (int i = 0; i <= sz[u]; i++) {
    BigInteger tmp = dp[u][i];
    tmp *= i;
    upd(dp[u][0], tmp);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int u, v;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  dp[1][0].out();
  return 0;
}
