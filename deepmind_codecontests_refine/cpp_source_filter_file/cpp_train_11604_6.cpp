#include <bits/stdc++.h>
using namespace std;
void RI(int& x) {
  x = 0;
  char c = getchar();
  while (!(c >= '0' && c <= '9' || c == '-')) c = getchar();
  bool flag = 1;
  if (c == '-') {
    flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (!flag) x = -x;
}
void RII(int& x, int& y) { RI(x), RI(y); }
void RIII(int& x, int& y, int& z) { RI(x), RI(y), RI(z); }
void RC(char& c) {
  c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
}
char RC() {
  char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
const long long mod = 1e9 + 7;
const long long LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;
const int N = 200005;
long long POW(int n, int m) {
  if (m == 0) return 1;
  if (m == 1) return n;
  long long tmp = POW(n, m / 2);
  if (m & 1) return tmp * tmp % mod * n % mod;
  return tmp * tmp % mod;
}
vector<int> g[N];
long long dp[N][2];
int a[N];
void dfs(int u, int fa) {
  for (int i = 0; i <= (int)g[u].size() - 1; i++) {
    int v = g[u][i];
    if (v != fa) {
      dfs(v, u);
    }
  }
  if (a[u] == 1) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int i = 0; i <= (int)g[u].size() - 1; i++) {
      int v = g[u][i];
      if (v != fa) {
        dp[u][1] = (dp[u][1] + dp[u][1] * dp[v][0]) % mod;
      }
    }
  } else {
    dp[u][0] = 1;
    dp[u][1] = 0;
    for (int i = 0; i <= (int)g[u].size() - 1; i++) {
      int v = g[u][i];
      if (v != fa) {
        dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % mod;
      }
    }
    for (int i = 0; i <= (int)g[u].size() - 1; i++) {
      int v = g[u][i];
      if (v != fa) {
        dp[u][1] = (dp[u][1] + dp[u][0] * POW(dp[v][0] + dp[v][1], mod - 2) %
                                   mod * dp[v][1]) %
                   mod;
      }
    }
  }
}
int main() {
  int n;
  RI(n);
  for (int i = 2; i <= n; i++) {
    int t;
    RI(t);
    g[i].push_back(t + 1);
    g[t + 1].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    RI(a[i]);
  }
  dfs(1, 0);
  cout << dp[1][1] << endl;
}
