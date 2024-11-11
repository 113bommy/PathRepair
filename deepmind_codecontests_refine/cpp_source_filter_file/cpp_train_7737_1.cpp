#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
long long int grd[maxn][maxn], minrow[maxn][maxn], minall[maxn][maxn],
    sum[maxn][maxn], cost[maxn][maxn];
bool mark[maxn][maxn];
long long int n, m, a, b;
vector<pair<int, int> > cells;
vector<int> ans;
inline long long int SUM(int i, int j, int ii, int jj) {
  return sum[ii][jj] - sum[ii][j] - sum[i][jj] + sum[i][j];
};
bool cmp(pair<int, int> i, pair<int, int> j) {
  int x = i.first, y = i.second;
  int xx = j.first, yy = j.second;
  if (cost[x][y] != cost[xx][yy]) return cost[x][y] < cost[xx][yy];
  if (x != xx) return x < xx;
  return y < yy;
}
int main() {
  scanf("%I64d%I64d%I64d%I64d", &n, &m, &a, &b);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%I64d", grd[i] + j);
      sum[i + 1][j + 1] = grd[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
    }
  for (int i = 0; i < n; i++) {
    deque<int> deq;
    for (int j = 0; j < m; j++) {
      while (((int)(deq).size()) and grd[i][deq.front()] > grd[i][j])
        deq.pop_front();
      deq.push_front(j);
      if (deq.back() <= j - b) deq.pop_back();
      if (j - b + 1 >= 0) minrow[i][j - b + 1] = grd[i][deq.back()];
    }
  }
  for (int j = 0; j <= m - b; j++) {
    deque<int> deq;
    for (int i = 0; i < n; i++) {
      while (((int)(deq).size()) and minrow[deq.front()][j] > minrow[i][j])
        deq.pop_front();
      deq.push_front(i);
      if (deq.back() <= i - a) deq.pop_back();
      if (i - a + 1 >= 0) minall[i - a + 1][j] = minrow[deq.back()][j];
    }
  }
  for (int i = 0; i <= n - a; i++)
    for (int j = 0; j <= m - b; j++)
      cost[i][j] = SUM(i, j, i + a, j + b) - minall[i][j] * a * b;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      mark[i][j] = (i > n - a) or (j > m - b);
      cells.push_back(make_pair(i, j));
    }
  sort(cells.begin(), cells.end(), cmp);
  for (int i = 0; i < ((int)(cells).size()); i++) {
    pair<int, int> cll = cells[i];
    if (mark[cll.first][cll.second]) continue;
    ans.push_back(i);
    for (int ii = max(0LL, cll.first - a + 1); ii < min(n, cll.first + a); ii++)
      for (int jj = max(0LL, cll.second - b + 1); jj < min(m, cll.second + b);
           jj++)
        mark[ii][jj] = true;
  }
  printf("%d\n", ((int)(ans).size()));
  for (auto id : ans)
    printf("%d%d%I64d\n", cells[id].first + 1, cells[id].second + 1,
           cost[cells[id].first][cells[id].second]);
  return 0;
}
