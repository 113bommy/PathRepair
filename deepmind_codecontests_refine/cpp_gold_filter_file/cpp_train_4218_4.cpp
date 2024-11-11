#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> x;
pair<bool, long long> ans[1005000];
int sz = 0;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
inline pair<long long, long long> merge(pair<long long, long long> a,
                                        pair<long long, long long> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
inline bool f(pair<long long, long long> a, pair<long long, long long> b) {
  return (long double)a.first / (long double)a.second <
         (long double)b.first / (long double)b.second;
}
void rec(pair<long long, long long> x) {
  if (!x.first || !x.second || (x.first == 1 && x.second == 1)) return;
  if (x.first == 1) {
    ans[++sz] = make_pair(1, x.second - 1);
    return;
  }
  if (x.second == 1) {
    ans[++sz] = make_pair(0, x.first - 1);
    return;
  }
  if (x.first > x.second) {
    ans[++sz] = make_pair(0, x.first / x.second);
    rec(make_pair(x.first % x.second, x.second));
  } else {
    ans[++sz] = make_pair(1, x.second / x.first);
    rec(make_pair(x.first, x.second % x.first));
  }
}
int main() {
  cin >> x.first >> x.second;
  if (gcd(x.first, x.second) != 1) {
    cout << "Impossible";
    return 0;
  }
  rec(x);
  for (int i = 1; i <= sz; i++) {
    printf("%I64d", ans[i].second);
    if (!ans[i].first)
      printf("A");
    else
      printf("B");
  }
  return 0;
}
