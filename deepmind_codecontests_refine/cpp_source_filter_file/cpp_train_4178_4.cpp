#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
using namespace std;
const int N = 1e5 + 5;
int x[N];
pair<pair<int, int>, int> y[N];
vector<int> vc;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.second == b.second)
    return a.first.first < b.first.first;
  else
    return a.second < b.second;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d %d %d", &y[i].first.first, &y[i].first.second, &y[i].second);
  sort(y + 1, y + 1 + m, cmp);
  bool f = true;
  for (int i = 1; i <= m; i++) {
    if (i == 1) {
      if (y[i].first.first != 1) {
        vc.push_back(0);
        f = false;
      }
    } else {
      if (y[i].second == y[i - 1].second) {
        if (y[i].first.first != y[i - 1].first.second + 1) {
          vc.push_back(y[i - 1].first.second);
          f = false;
        }
      } else {
        if (f) vc.push_back(y[i - 1].first.second);
        f = true;
        if (y[i].first.first != 1) vc.push_back(0), f = false;
      }
    }
  }
  if (m && f) vc.push_back(y[m].first.second);
  if (vc.size() == 0) return 0 * puts("0");
  sort(vc.begin(), vc.end());
  sort(x + 1, x + 1 + n);
  x[n + 1] = 1000000000;
  int ans = INT_MAX;
  for (int i = 1; i <= n + 1; i++) {
    int t = lower_bound(vc.begin(), vc.end(), x[i]) - vc.begin();
    ans = min(ans, i - 1 + (int)vc.size() - t);
  }
  printf("%d\n", ans);
  return 0;
}
