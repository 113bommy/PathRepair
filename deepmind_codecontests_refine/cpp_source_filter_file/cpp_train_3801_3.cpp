#include <bits/stdc++.h>
using namespace std;
unsigned long long calc(unsigned long long n, unsigned long long m) {
  return n * (n + 1) * (m + 1) - (n + m + 2) * n * (n + 1) / 2 +
         n * (n + 1) * (2 * n + 1) / 6;
}
int main() {
  long long x;
  scanf("%lld", &x);
  vector<pair<unsigned long long, unsigned long long> > ans;
  long long gor = x + 1;
  for (unsigned long long n = 1; n * n * n <= 2 * x; n++) {
    unsigned long long l = n, r = gor;
    while (r - l > 1) {
      unsigned long long m = (l + r) / 2;
      unsigned long long tmp = calc(n, m);
      if (tmp <= x) {
        l = m;
      } else {
        r = m;
      }
    }
    unsigned long long cur = calc(n, l);
    if (cur > x) break;
    if (cur == x) {
      ans.push_back(make_pair(n, l));
      if (n != l) {
        ans.push_back(make_pair(l, n));
      }
    }
    gor = l;
  }
  sort(ans.begin(), ans.end());
  vector<pair<unsigned long long, unsigned long long> > go;
  for (int i = 0; i < ans.size(); i++) {
    if (i != 0 && go.back() == ans[i]) continue;
    go.push_back(ans[i]);
  }
  ans = go;
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  }
  return 0;
}
