#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long nbits = 1000;
string s, cur;
long long k, m;
long long dp[nbits + 1][nbits + 1][2];
long long cnt(long long num) {
  long long res = 0;
  while (num > 1) {
    ++res;
    long long s = 0;
    while (num) {
      s += (num & 1);
      num >>= 1;
    }
    num = s;
  }
  return res;
}
vector<string> ans;
long long solve(long long idx, long long sum, bool flag) {
  if (idx == m) {
    if (sum == 0) {
      return 1;
    } else {
      return 0;
    }
  }
  if (dp[idx][sum][flag] != -1) {
    return dp[idx][sum][flag];
  }
  long long res = 0;
  if (flag) {
    res = (res + solve(idx + 1, sum, flag)) % MOD;
    res = (res + solve(idx + 1, sum - 1, flag)) % MOD;
  } else {
    for (char ch = '0'; ch <= '1'; ch++) {
      long long val = ch - '0';
      if (ch < s[idx]) {
        res = (res + solve(idx + 1, sum - val, true)) % MOD;
      } else if (ch == s[idx]) {
        res = (res + solve(idx + 1, sum - val, flag)) % MOD;
      }
    }
  }
  res %= MOD;
  res += MOD;
  res %= MOD;
  return dp[idx][sum][flag] = res % MOD;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> k;
  if (k == 0) {
    if (s == "0") {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
    return 0;
  }
  m = (long long)s.length();
  vector<long long> cand;
  for (long long bits = 1; bits <= nbits; bits++) {
    long long c = cnt(bits);
    if (c == k - 1) {
      cand.push_back(bits);
    }
  }
  long long res = 0;
  memset(dp, -1, sizeof dp);
  for (auto& candidate : cand) {
    res = (res + solve(0, candidate, false)) % MOD;
  }
  if (k == 1) {
    --res;
  }
  res %= MOD;
  res += MOD;
  res %= MOD;
  cout << res % MOD << '\n';
  return 0;
}
