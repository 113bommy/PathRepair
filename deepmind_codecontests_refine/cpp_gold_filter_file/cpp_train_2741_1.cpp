#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 5002;
constexpr int mod = 1e9 + 7;
string x, y;
int n, m;
int cache[N][N];
int dp(int a, int b) {
  if (a == n or b == m) return 0;
  int &rv = cache[a][b];
  if (~rv) return rv;
  rv = dp(a, b + 1);
  if (x[a] == y[b]) rv += 1 + dp(a + 1, b + 1), rv %= mod;
  return rv;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> x >> y;
  n = x.size(), m = y.size();
  memset(cache, -1, sizeof cache);
  dp(0, 0);
  int result = 0;
  for (int i = 0; i < n; i++) result += dp(i, 0), result %= mod;
  cout << result << endl;
}
