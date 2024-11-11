#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < v.size(); i++) os << v[i] << " ";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (typename set<T>::iterator it = v.begin(); it != v.end(); it++)
    os << *it << " ";
}
const int mod = 998244353;
const int N = 5e2 + 5;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int dp[2][N][N];
int f[N];
int ans;
int main() {
  int n, K;
  cin >> n >> K;
  dp[0][0][0] = 1;
  for (int i = (0); i <= (n); i++) {
    memset(dp[!(i & 1)], 0, sizeof(dp[!(i & 1)]));
    for (int j = (0); j <= (i); j++) {
      for (int k = (0); k <= (i); k++) {
        (dp[!(i & 1)][j + 1][max(k, j + 1)] += dp[i & 1][j][k]) %= mod;
        (dp[!(i & 1)][1][max(1, k)] += dp[i & 1][j][k]) %= mod;
      }
    }
  }
  for (int k = (0); k <= (n); k++) {
    f[k] = dp[n & 1][1][k];
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (n); j++) {
      if (i * j >= K) {
        continue;
      }
      ans += (long long)f[i] * f[j] % mod;
      ans %= mod;
    }
  }
  cout << (long long)ans * ((1 + mod) / 2) % mod;
  return 0;
}
