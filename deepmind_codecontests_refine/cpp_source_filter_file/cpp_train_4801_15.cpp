#include <bits/stdc++.h>
using namespace std;
const int shift = 400;
const int max_n = 400;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
int d[max_n + shift + 1][max_n + shift + 1];
int dist(pair<int, int> fst, pair<int, int> snd) {
  return d[shift + snd.first - fst.first][shift + snd.second - fst.second];
}
void calcd() {
  int x = shift, y = shift, cur = 0, dir = 0, len = 1;
  while ((x >= 0) && (y >= 0) && (x < max_n + shift) && (y < max_n + shift)) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < len; ++j) {
        x += dx[dir], y += dy[dir], cur++;
        if ((x >= 0) && (y >= 0) && (x < max_n + shift) && (y < max_n + shift))
          d[x][y] = cur;
      }
      dir = (dir + 1) % 4;
    }
    len++;
  }
}
map<int, vector<pair<int, int> > > colors;
int a[max_n][max_n], b[max_n][max_n];
deque<pair<int, int> > q;
int main() {
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &a[i][j]), colors[a[i][j]].push_back(make_pair(i, j));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &b[i][j]);
  calcd();
  scanf("%d%d", &x, &y);
  long long res = 0, sum = 0;
  q.push_back(make_pair(x - 1, y - 1));
  int pc = a[x - 1][y - 1];
  while (q.size() > 0) {
    pair<int, int> cur = q.front();
    q.pop_front();
    int gc = b[cur.first][cur.second];
    if ((pc != 0) && (pc != gc) && (gc != -1)) {
      vector<pair<int, pair<int, int> > > pos;
      for (int i = 0; i < colors[pc].size(); ++i)
        pos.push_back(make_pair(dist(colors[pc][i], cur), colors[pc][i]));
      sort(pos.begin(), pos.end());
      sum += pos.size();
      for (int i = 0; i < pos.size(); ++i)
        if (pos[i].second != cur) q.push_back(pos[i].second);
      colors[pc].clear();
      pc = gc;
      res += sum;
    }
  }
  printf("%lld\n", res);
  return 0;
}
