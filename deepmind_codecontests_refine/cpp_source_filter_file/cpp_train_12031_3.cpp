#include <bits/stdc++.h>
using namespace std;
multiset<pair<long long, pair<long long, long long> > > s;
long long ans, n;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > d || b > c)
      if (a - d >= c - b)
        s.insert({a + b, {a, b}}), s.insert({c + d, {c, d}});
      else if (a > d)
        ans += a - d;
      else
        ans -= c - b;
  }
  while (s.size()) {
    auto x = (*s.rbegin());
    ans += x.second.first;
    s.erase(s.find(x));
    x = (*s.rbegin());
    ans -= x.second.second;
    s.erase(s.find(x));
  }
  cout << ans;
  return 0;
}
