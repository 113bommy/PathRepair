#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<pair<int, int> > line[MAXN];
vector<pair<int, int> > column[MAXN];
vector<pair<int, int> > d1[2 * MAXN];
vector<pair<int, int> > d2[2 * MAXN];
int n, m;
int x, y;
int val[MAXN];
int vv[MAXN];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    line[x].push_back(make_pair(x, i));
    column[y].push_back(make_pair(y, i));
    if (x >= y)
      d1[x - y + 1].push_back(make_pair(x, i));
    else
      d1[n + y - x].push_back(make_pair(x, i));
    x = n + 1 - x;
    if (x >= y)
      d2[x - y + 1].push_back(make_pair(x, i));
    else
      d2[n + y - x].push_back(make_pair(x, i));
  }
  for (int i = 1; i <= n; i++) {
    sort(line[i].begin(), line[i].end());
    sort(column[i].begin(), column[i].end());
    for (size_t j = 0; j + 1 < line[i].size(); j++)
      val[line[i][j].second]++, val[line[i][j + 1].second]++;
    for (size_t j = 0; j + 1 < column[i].size(); j++)
      val[column[i][j].second]++, val[column[i][j + 1].second]++;
  }
  for (int i = 1; i <= 2 * n; i++) {
    sort(d1[i].begin(), d1[i].end());
    sort(d2[i].begin(), d2[i].end());
    for (size_t j = 0; j + 1 < d1[i].size(); j++)
      val[d1[i][j].second]++, val[d1[i][j + 1].second]++;
    for (size_t j = 0; j + 1 < d2[i].size(); j++)
      val[d2[i][j].second]++, val[d2[i][j + 1].second]++;
  }
  for (int i = 0; i < m; i++) vv[val[i]]++;
  for (int i = 0; i <= 8; i++) cout << vv[i] << ' ';
  cout << '\n';
  return 0;
}
