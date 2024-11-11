#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7;
int n, m, r, a[N][N];
vector<pair<int, int> > o1, o2;
void geto() {
  int dy = r;
  for (int dx = (0); dx < (r + 1); ++dx) {
    while (dx * dx + dy * dy > r * r) dy--;
    o1.push_back({dx, dy});
    if (dx) o1.push_back({-dx, dy});
  }
  for (auto p : o1)
    for (auto v : o1) o2.push_back({p.first + v.first, -p.second - v.second});
  sort((o2).begin(), (o2).end());
  vector<pair<int, int> > ret;
  for (int i = (0); i < (((int)(o2).size())); ++i)
    if (!i || o2[i].first != o2[i - 1].first)
      ret.push_back({o2[i].first, -o2[i].second});
  swap(ret, o2);
}
int dp[N][N], mx[N];
pair<int, int> rt[N][N];
int main() {
  scanf("%d%d%d", &n, &m, &r);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) scanf("%d", &a[i][j]);
  geto();
  for (int i = (r); i < (n - r); ++i) {
    for (auto v : o1)
      for (int j = (-v.second); j < (v.second + 1); ++j)
        dp[i][r] += a[i + v.first][r + j];
    for (int j = (r + 1); j < (m - r); ++j) {
      dp[i][j] = dp[i][j - 1];
      for (auto v : o1)
        dp[i][j] +=
            a[i + v.first][j + v.second] - a[i + v.first][j - v.second - 1];
    }
  }
  for (int i = (r); i < (n - r); ++i) {
    for (int j = (m - r) - 1; j >= (r); --j) {
      rt[i][j] = rt[i][j + 1];
      if (rt[i][j + 1].first == dp[i][j])
        rt[i][j].second++;
      else if (rt[i][j + 1].first < dp[i][j])
        rt[i][j] = {dp[i][j], 1};
    }
  }
  pair<int, long long> ans = {0, 0};
  for (int i = (r); i < (n - r); ++i) {
    fill_n(mx, n, 0);
    for (int j = (r); j < (m - r); ++j) {
      for (int k = (0); k < (i); ++k) mx[k] = max(mx[k], j);
      for (int k = (i); k < (n); ++k) mx[k] = max(mx[k], j + 1);
      for (auto v : o2)
        if (i + v.first >= 0 && i + v.first < n)
          mx[i + v.first] = max(mx[i + v.first], j + v.second + 1);
      for (int k = (r); k < (n - r); ++k)
        if (mx[k] < m - r) {
          pair<int, int> tmp = rt[k][mx[k]];
          tmp.first += dp[i][j];
          if (tmp.first == ans.first)
            ans.second += tmp.second;
          else if (tmp.first > ans.first)
            ans = tmp;
        }
    }
  }
  printf("%d %lld", ans.first, ans.second);
  return 0;
}
