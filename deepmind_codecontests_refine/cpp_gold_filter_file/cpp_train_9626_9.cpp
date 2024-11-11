#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, k, s, m;
  scanf("%lld", &n);
  vector<pair<long long, long long>> a;
  for (i = 0; i < n; ++i) {
    long long x;
    scanf("%lld", &x);
    a.push_back({x, 0});
  }
  scanf("%lld", &m);
  for (i = 0; i < m; ++i) {
    long long x;
    scanf("%lld", &x);
    a.push_back({x, 1});
  }
  sort(a.begin(), a.end());
  long long best = 3 * n - 3 * m;
  long long s1 = 3 * n;
  long long s2 = 3 * m;
  long long ans1, ans2;
  ans1 = 3 * n;
  ans2 = 3 * m;
  for (auto i : a) {
    if (i.second) {
      s2--;
    } else {
      s1--;
    }
    if (s1 - s2 > best) {
      best = s1 - s2;
      ans1 = s1;
      ans2 = s2;
    }
  }
  printf("%lld:%lld\n", ans1, ans2);
  return 0;
}
