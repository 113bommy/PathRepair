#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
pair<pair<int, int>, pair<int, int> > q[maxn + 5];
int n;
int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int id[256];
bool print[maxn + 5][maxn + 5], vis[maxn + 5][maxn + 5];
long long ans = 0;
int main() {
  scanf("%d", &n);
  int curx = 0, cury = 0;
  id[int('L')] = 0;
  id[int('R')] = 1;
  id[int('U')] = 2;
  id[int('D')] = 3;
  vector<int> X, Y;
  X.push_back(curx), Y.push_back(cury);
  X.push_back(curx + 1), Y.push_back(cury + 1);
  for (int i = (0), _end_ = (n); i != _end_; ++i) {
    char s[3];
    static int first;
    scanf("%s%d", s, &first);
    int tmp = id[(int)s[0]];
    int lstx = curx, lsty = cury;
    curx = lstx + walk[tmp][0] * first, cury = lsty + walk[tmp][1] * first;
    q[i] = make_pair(make_pair(lstx, lsty), make_pair(curx, cury));
    X.push_back(curx), Y.push_back(cury);
    X.push_back(curx + 1), Y.push_back(cury + 1);
  }
  sort((X).begin(), (X).end());
  sort((Y).begin(), (Y).end());
  X.resize(unique((X).begin(), (X).end()) - X.begin());
  Y.resize(unique((Y).begin(), (Y).end()) - Y.begin());
  for (int i = (0), _end_ = (n); i != _end_; ++i) {
    q[i].first.first =
        lower_bound((X).begin(), (X).end(), q[i].first.first) - X.begin();
    q[i].second.first =
        lower_bound((X).begin(), (X).end(), q[i].second.first) - X.begin();
    q[i].first.second =
        lower_bound((Y).begin(), (Y).end(), q[i].first.second) - Y.begin();
    q[i].second.second =
        lower_bound((Y).begin(), (Y).end(), q[i].second.second) - Y.begin();
    for (int j = (min(q[i].first.first, q[i].second.first)),
             _end_ = (max(q[i].first.first, q[i].second.first) + 1);
         j != _end_; ++j)
      for (int k = (min(q[i].first.second, q[i].second.second)),
               _end_ = (max(q[i].first.second, q[i].second.second) + 1);
           k != _end_; ++k)
        print[j][k] = 1;
  }
  static pair<int, int> q[maxn * maxn + 5];
  int nn = (int((X).size())), mm = (int((Y).size()));
  for (int i = (0), _end_ = (nn); i != _end_; ++i)
    for (int j = (0), _end_ = (mm); j != _end_; ++j) {
      if (print[i][j]) continue;
      if (vis[i][j]) continue;
      int tot = 0;
      q[tot++] = make_pair(i, j);
      bool flag = 0;
      for (int k = 0; k < tot; ++k) {
        const pair<int, int> &first = q[k];
        if (!first.first || first.first == nn - 1 || !first.second ||
            first.second == mm - 1)
          flag = 1;
        for (int l = (0), _end_ = (4); l != _end_; ++l) {
          pair<int, int> second =
              make_pair(first.first + walk[l][0], first.second + walk[l][1]);
          if (second.first < 0 || second.first >= nn || second.second < 0 ||
              second.second >= mm)
            continue;
          if (print[second.first][second.second]) continue;
          if (vis[second.first][second.second]) continue;
          vis[second.first][second.second] = 1;
          q[tot++] = second;
        }
      }
      if (flag) continue;
      for (int i = (0), _end_ = (tot); i != _end_; ++i)
        print[q[i].first][q[i].second] = 1;
    }
  ans = 0;
  for (int i = (0), _end_ = (nn - 1); i != _end_; ++i)
    for (int j = (0), _end_ = (mm - 1); j != _end_; ++j)
      if (print[i][j]) ans += (long long)(X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
  cout << ans << endl;
  return 0;
}
