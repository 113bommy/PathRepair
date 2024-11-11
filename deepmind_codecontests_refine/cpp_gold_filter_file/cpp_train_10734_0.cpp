#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 998244353;
ll dp[2][2][207];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dat(n);
  for (int i = 0; i < n; i++) cin >> dat[i];
  for (int v = 1; v <= 200; v++) {
    dp[0][0][v] = (dat[0] == -1 || dat[0] == v) ? 1 : 0;
  }
  for (int i = 1; i <= n - 1; i++) {
    int from = (i + 1) & 1;
    int to = i & 1;
    vector<ll> larger(202), smaller(202);
    for (int v = 200; v >= 1; --v) {
      larger[v] = (larger[v + 1] + dp[from][1][v]) % mod;
    }
    for (int v = 1; v <= 200; ++v) {
      smaller[v] = (smaller[v - 1] + dp[from][0][v]) % mod;
    }
    for (int v = 1; v <= 200; v++) {
      dp[to][0][v] = (smaller[v] + larger[v + 1]) % mod;
      dp[to][1][v] = (larger[v + 1] + dp[from][0][v]) % mod;
    }
    for (int v = 1; v <= 200; v++)
      for (int y = 0; y < 2; y++) {
        if (dat[i] != -1 && dat[i] != v) dp[to][y][v] = 0;
      }
  }
  ll res = 0;
  for (int v = 1; v <= 200; v++) {
    res = (res + dp[(n - 1) & 1][1][v]) % mod;
  }
  cout << res << endl;
}
