#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int n, m, a, b, d[N][N];
long long dp[N][N];
long long sum[N][N];
long long gsum(int lx, int ly, int rx, int ry) {
  return sum[rx][ry] - sum[lx - 1][ry] - sum[rx][ly - 1] + sum[lx - 1][ly - 1];
}
void ini() {
  for (int i = (1); i < (n + 1); ++i) {
    priority_queue<pair<int, int> > stk;
    for (int j = (m + 1) - 1; j >= (1); --j) {
      stk.push({-d[i][j], j});
      while (stk.top().second >= j + b) stk.pop();
      dp[i][j] = -stk.top().first;
    }
  }
  for (int j = (1); j < (m + 1); ++j) {
    priority_queue<pair<int, int> > stk;
    for (int i = (n + 1) - 1; i >= (1); --i) {
      stk.push({-dp[i][j], i});
      while (stk.top().second >= i + a) stk.pop();
      dp[i][j] = -stk.top().first;
    }
  }
  for (int i = (1); i < (n + 1); ++i)
    for (int j = (1); j < (m + 1); ++j) {
      sum[i][j] = d[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
}
bool use[N][N];
bool ck(pair<int, int> p) {
  int x = -p.first, y = -p.second;
  return !use[x][y] && !use[x + a - 1][y] && !use[x][y + b - 1] &&
         !use[x + a - 1][y + b - 1];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = (1); i < (n + 1); ++i)
    for (int j = (1); j < (m + 1); ++j) scanf("%d", &d[i][j]);
  ini();
  priority_queue<pair<int, pair<int, int> > > stk;
  for (int i = (1); i < (n + 2 - a); ++i)
    for (int j = (1); j < (m + 2 - b); ++j) {
      stk.push(
          {-(gsum(i, j, i + a - 1, j + b - 1) - dp[i][j] * a * b), {-i, -j}});
    }
  vector<pair<long long, pair<int, int> > > ans;
  while (1) {
    while (!stk.empty() && !ck(stk.top().second)) stk.pop();
    if (stk.empty())
      break;
    else
      ans.push_back(stk.top());
    auto e = stk.top().second;
    for (int i = (-e.first); i < (-e.first + a); ++i)
      for (int j = (-e.second); j < (-e.second + b); ++j) use[i][j] = true;
  }
  printf("%d\n", ((int)(ans).size()));
  for (auto e : ans)
    printf("%d %d %lld\n", -e.second.first, -e.second.second, -e.first);
  return 0;
}
