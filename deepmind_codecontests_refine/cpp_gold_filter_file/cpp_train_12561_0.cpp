#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> p[200001];
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first - a.second > b.first - b.second;
}
int main(void) {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%lld %lld", &p[i].first, &p[i].second);
  sort(p + 1, p + 1 + n, compare);
  long long sum = 0, ans;
  long long mn = 2e18;
  int bb = b;
  for (int i = 1; i <= n; i++) {
    if (bb) {
      bb--;
      sum += max(p[i].second, p[i].first);
      mn = min(mn, max(0LL, p[i].first - p[i].second));
    } else
      sum += p[i].second;
  }
  ans = sum;
  if (b == 0) return !printf("%lld", ans);
  for (int i = 1; i <= n; i++) {
    long long temp = (p[i].first) << (long long)a;
    long long cmp = sum;
    if (i <= b) {
      cmp -= max(p[i].first, p[i].second);
      cmp += max(temp, p[i].second);
    } else {
      cmp -= p[i].second + mn;
      cmp += max(temp, p[i].second);
    }
    ans = max(ans, cmp);
  }
  printf("%lld", ans);
  return 0;
}
