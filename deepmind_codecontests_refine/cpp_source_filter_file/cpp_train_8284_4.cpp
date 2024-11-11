#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long nod(long long n) {
  string s = to_string(n);
  return (long long)s.length();
}
long long modexp(long long x, long long y) {
  x %= 1000000007;
  long long res = 1;
  while (y) {
    if (y & 1) res *= x, res %= 1000000007;
    x *= x;
    y >>= 1;
    x %= 1000000007;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long cnt = 0;
  long long ans = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == 'a')
      cnt++;
    else {
      ans += pow(2, cnt);
      ans = (ans - 1 + (long long)100 * 1000000007) % 1000000007;
      ans %= 1000000007;
    }
  }
  cout << ans;
}
