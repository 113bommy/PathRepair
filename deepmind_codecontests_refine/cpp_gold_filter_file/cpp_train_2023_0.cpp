#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m;
    b /= 2;
    a = ((a % m) * (a % m)) % m;
  }
  return ans % m;
}
string s;
long long dp[1000005][3][2];
long long solve(long long id, long long prev, bool bomb) {
  if (prev == 2) return 0;
  if (prev < 0) return 0;
  if (id == s.length()) {
    if (prev > 0) return 0;
    return 1;
  }
  long long ans = 0;
  if (dp[id][prev][bomb] != -1) return dp[id][prev][bomb];
  if (s[id] != '?') {
    if (s[id] == '*') {
      if ((!bomb) && (prev == 0) && (id != 0)) return 0;
      ans = solve(id + 1, 0, 1);
      ans = (ans % (long long)(1000 * 1000 * 1000 + 7));
    } else {
      if (prev > 0) return 0;
      long long n = s[id] - '0';
      if (bomb) n--;
      ans = solve(id + 1, n, 0);
      ans = (ans % (long long)(1000 * 1000 * 1000 + 7));
    }
  } else {
    if (id == 0) {
      ans = solve(1, prev, 1);
      ans = (ans % (long long)(1000 * 1000 * 1000 + 7));
      for (long long i = 0; i < 2; i++) {
        ans += solve(id + 1, i, 0);
        ans = (ans % (long long)(1000 * 1000 * 1000 + 7));
      }
    } else {
      if (bomb) {
        ans = solve(id + 1, 0, 1);
        ans = ans % (long long)(1000 * 1000 * 1000 + 7);
        for (long long i = 0; i < 2; i++) {
          ans += solve(id + 1, i, 0);
          ans = (ans % (long long)(1000 * 1000 * 1000 + 7));
        }
      } else {
        if (prev == 0) {
          ans = solve(id + 1, 0, 0);
          ans = ans % (long long)(1000 * 1000 * 1000 + 7);
          ans += solve(id + 1, 1, 0);
          ans = ans % (long long)(1000 * 1000 * 1000 + 7);
        } else {
          ans = solve(id + 1, 0, 1);
          ans %= (long long)(1000 * 1000 * 1000 + 7);
        }
      }
    }
  }
  return dp[id][prev][bomb] = (ans % (long long)(1000 * 1000 * 1000 + 7));
}
int main() {
  cin >> s;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0);
}
