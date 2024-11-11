#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
int dxx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dyy[] = {0, +1, 0, -1, +1, -1, +1, -1};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
vector<pair<long long, long long> > ans;
int main() {
  long long x, i, sz = 0, l, y;
  scanf("%lld", &x);
  l = min(x, 1000000LL);
  for (i = 1; i <= l; i++) {
    y = x * 6LL;
    if (y % i) continue;
    y /= i;
    if (y % (i + 1)) continue;
    y /= (i + 1);
    y += (i - 1);
    if (y % 3) continue;
    y /= 3;
    if (y < i) continue;
    ans.push_back(make_pair(i, y));
    if (i == y)
      sz++;
    else
      sz += 2;
  }
  printf("%lld\n", sz);
  for (i = 0; i < ans.size(); i++)
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  for (i = ans.size() - 1; ~i; i--)
    if (ans[i].first != ans[i].second)
      printf("%lld %lld\n", ans[i].second, ans[i].first);
  return 0;
}
