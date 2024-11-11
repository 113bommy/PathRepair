#include <bits/stdc++.h>
using namespace std;
pair<tuple<long long, long long>, bool> solve(long long a, long long b,
                                              long long c) {
  function<pair<tuple<long long, long long>, bool>(long long, long long)> f =
      [&](long long a, long long b) {
        if (a == 0) {
          return make_pair(make_tuple(0ll, c % b == 0ll ? c / b : 0ll),
                           c % b == 0);
        }
        auto res = f(b % a, a);
        long long x, y;
        tie(x, y) = res.first;
        return make_pair(make_tuple(y - b / a * x, x), res.second);
      };
  return f(a, b);
}
string to_rev_string(long long x) {
  string s;
  do {
    s += '0' + x % 10;
    x /= 10;
  } while (x > 0);
  return s;
}
int main() {
  ios::sync_with_stdio(false);
  long long x, y;
  cin >> x >> y;
  auto res = solve(x, y, 1);
  if (!res.second) {
    puts("Impossible");
    return 0;
  }
  long long w, z;
  tie(z, w) = res.first;
  w = -w;
  if (z < 0 || w < 0) {
    z += y;
    w += x;
  }
  long long oo = 1ll << 61;
  auto a = make_pair(x - w, y - z);
  auto b = make_pair(w, z);
  string ans = "";
  while (!(a == make_pair(1ll, 0ll) && b == make_pair(0ll, 1ll))) {
    if (a.first <= b.first && a.second <= b.second) {
      long long e = a.first > 0 ? b.first / a.first : oo;
      long long f = a.second > 0 ? b.second / a.second : oo;
      long long d = min(e, f);
      b.first -= d * a.first;
      b.second -= d * a.second;
      if (b.first < 0 || b.second < 0 || b.first == 0 && b.second == 0) {
        puts("Impossible");
        return 0;
      }
      ans += "A";
      ans += to_rev_string(d);
    } else if (b.first <= a.first && b.second <= a.second) {
      long long e = b.first > 0 ? a.first / b.first : oo;
      long long f = b.second > 0 ? a.second / b.second : oo;
      long long d = min(e, f);
      a.first -= d * b.first;
      a.second -= d * b.second;
      if (a.first < 0 || a.second < 0 || a.first == 0 && a.second == 0) {
        puts("Impossible");
        return 0;
      }
      ans += "B";
      ans += to_rev_string(d);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}
