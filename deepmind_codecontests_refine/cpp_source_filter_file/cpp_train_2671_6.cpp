#include <bits/stdc++.h>
using namespace std;
long long root(long long x) {
  long long left = 0, right = 1e9;
  long long mid, ans;
  while (left <= right) {
    mid = (left + right) >> 1;
    if (mid * mid <= x) {
      ans = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  return ans;
}
vector<long long> g;
void init() {
  g.clear();
  for (long long i = 2; i <= 1e6; i++) {
    double t = 1.0 * i * i * i;
    long long s = i * i * i;
    while (t <= 1e18) {
      long long root_s = root(s);
      if (root_s * root_s < s) g.push_back(s);
      t *= i;
      s *= i;
    }
  }
  sort(g.begin(), g.end());
  int sz = unique(g.begin(), g.end()) - g.begin();
}
int main() {
  init();
  int q;
  scanf("%d", &q);
  long long l, r;
  while (q--) {
    scanf("%I64d %I64d", &l, &r);
    int ans1 =
        upper_bound(g.begin(), g.end(), r) - lower_bound(g.begin(), g.end(), l);
    int ans2 = root(r) - root(l - 1);
    printf("%d\n", ans1 + ans2);
  }
  return 0;
}
