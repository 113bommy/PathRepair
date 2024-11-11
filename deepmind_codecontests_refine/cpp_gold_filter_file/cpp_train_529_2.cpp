#include <bits/stdc++.h>
const int M = 1e5 + 7;
const long long N = 1e18 + 7;
using namespace std;
int n, l, t, ans, sum;
pair<int, int> p[M];
int main() {
  scanf("%d %d %d", &n, &l, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].first, &p[i].second);
    p[i].second += p[i].first;
  }
  for (int i = 0; i < n; ++i) {
    if (p[i].first - p[i - 1].second >= t)
      ans += (p[i].first - p[i - 1].second) / t;
    sum += (p[i].first - p[i - 1].second) % t;
    sum += p[i].second - p[i].first;
  }
  cout << ans + (l - (ans * t + sum)) / t;
  return 0;
}
