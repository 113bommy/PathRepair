#include <bits/stdc++.h>
using namespace std;
long long power[15];
long long prob[15][15];
long long py[1 << 15][15];
long long dp[1 << 15];
const long long mod = 1e9 + 7;
long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> power[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      prob[i][j] = power[i] * ksm(power[i] + power[j], mod - 2) % mod;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1 << n; j++) {
      long long cur = 1;
      for (int k = 0; k < n; k++) {
        if (j & (1 << k)) cur = cur * prob[k][i] % mod;
      }
      py[j][i] = cur;
    }
  }
  for (int i = 1; i < 1 << n; i++) {
    long long res = 1;
    vector<int> pos;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) pos.push_back(j);
    }
    int sz = pos.size();
    for (int j = 1; j < (1 << sz) - 1; j++) {
      int val = 0;
      for (int k = 0; k < sz; k++) {
        if (j & (1 << k)) val += 1 << pos[k];
      }
      long long cur = dp[val];
      for (int k = 0; k < sz; k++) {
        if (!(j & (1 << k))) cur = cur * py[val][pos[k]] % mod;
      }
      res = (res - cur) % mod;
    }
    dp[i] = res;
  }
  long long ans = 0;
  for (int i = 0; i < 1 << n; i++) {
    long long cur = 1;
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j))) cur = cur * py[i][j] % mod;
    }
    ans = (ans + (long long)__builtin_popcount(i) * dp[i] % mod * cur) % mod;
  }
  cout << (ans + mod) % mod << '\n';
}
