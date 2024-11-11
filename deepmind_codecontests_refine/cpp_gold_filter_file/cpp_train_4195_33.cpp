#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " = " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1 << " || ";
  __f(comma + 1, args...);
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ; ";
  return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
  return os << "[ " << p.first << ", " << p.second << "]";
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b * c < a) {
      cout << -1 << '\n';
      continue;
    }
    long long ans = a;
    long long times = a / (b * d);
    long long sub = (times * (times + 1)) / 2;
    ans = max(ans, a * 2 - d * b);
    ans = max(ans, a * (times + 1) - sub * d * b);
    cout << ans << '\n';
  }
  return 0;
}
