#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long pw(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long t = pw(a, b / 2, p);
  t = (t * t) % p;
  if (b % 2) return (a * t) % p;
  return t;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  string t = s;
  t[0] = s[0];
  t[1] = s[2];
  t[2] = s[4];
  t[3] = s[3];
  t[4] = s[1];
  long long x = stoll(t);
  x = pw(x, 5, 100000);
  t = to_string(x);
  long long y = t.size();
  reverse(t.begin(), t.end());
  while (y < 5) {
    t += '0';
    y++;
  }
  reverse(t.begin(), t.end());
  cout << x;
  return 0;
}
