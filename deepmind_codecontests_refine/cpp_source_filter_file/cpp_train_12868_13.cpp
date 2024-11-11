#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
long long n, ans, u[100100];
pair<long long, long long> l[100100], r[100100];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &u[i]);
  for (int i = 1; i <= n; ++i)
    if (l[i - 1].second >= u[i])
      l[i] = {l[i - 1].first + l[i - 1].second + 1 - u[i], l[i - 1].second + 1};
    else
      l[i] = {l[i - 1].first, u[i]};
  for (int i = n; i; --i)
    if (r[i + 1].second >= u[i])
      r[i] = {r[i + 1].first + r[i + 1].second + 1 - u[i], r[i + 1].second + 1};
    else
      r[i] = {r[i + 1].first, u[i]};
  ans = inf;
  for (int i = 1; i <= n; ++i) {
    long long s =
        l[i].first + r[i + 1].first + (l[i].second == r[i + 1].second);
    ans = min(ans, s);
  }
  printf("%lld", ans);
  return 0;
}
