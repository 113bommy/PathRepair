#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAXN = 2e5 + 7;
long long len(long long n) {
  long long res = 0;
  while (n) {
    n /= 10;
    ++res;
  }
  return res;
}
string to_string_(long long n) {
  string res = "";
  while (n) {
    res += '0' + (n % 10);
    n /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
long long stoi_(string s) {
  long long res = 0;
  for (long long i = 0; i < s.size(); ++i) {
    res = res * 10 + (s[i] - '0');
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cout.precision(40);
  long long k, p;
  cin >> k >> p;
  long long ans = 0;
  for (long long i = 1; i <= k; ++i) {
    long long add1 = i;
    for (long long j = 0; j < len(k); ++j) {
      add1 *= 10;
    }
    ans += add1;
    string s = to_string_(i);
    reverse(s.begin(), s.end());
    ans += stoi_(s);
    ans %= p;
  }
  cout << (ans + p) % p;
  return 0;
}
