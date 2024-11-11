#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
using namespace std;
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
long long prime(long long p) {
  if (p < 4) return true;
  if (p % 2 == 0) return false;
  if (p % 3 == 0) return false;
  for (long long i = 5; i * i <= p; i += 6) {
    if (!(p % i)) return i;
    if (!(p % (i + 2))) return false;
  }
  return true;
}
long long inv(long long a, long long mod) { return powmod(a, mod - 2, mod); }
void solve(long long ppppppppp = 1) {
  string s;
  cin >> s;
  long long a = s.size();
  vector<vector<long long>> pos(26);
  for (long long i = 0; i < 26; i++) pos[i].push_back(0);
  for (long long i = 0; i < a; i++) {
    pos[s[i] - 'a'].push_back(i);
  }
  for (long long i = 0; i < 26; i++) pos[i].push_back(a - 1);
  long long l = 1;
  long long r = a;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    long long check = 0;
    for (long long i = 0; i < 26; i++) {
      long long check1 = 1;
      long long qq = pos[i].size();
      for (long long j = 0; j < qq - 1; j++)
        if (pos[i][j + 1] - pos[i][j] > mid) check1 = 0;
      if (check1 == 1) check = 1;
    }
    if (check == 1)
      r = mid;
    else
      l = mid + 1;
  }
  long long mid = r;
  long long check = 0;
  for (long long i = 0; i < 26; i++) {
    long long check1 = 1;
    long long qq = pos[i].size();
    for (long long j = 0; j < qq - 1; j++)
      if (pos[i][j + 1] - pos[i][j] > mid) check1 = 0;
    if (check1 == 1) check = 1;
  }
  if (check == 1) l = mid;
  cout << l;
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tututu;
  tututu = 1;
  for (long long qwerty = 0; qwerty < tututu; qwerty++) solve();
  return 0;
}
