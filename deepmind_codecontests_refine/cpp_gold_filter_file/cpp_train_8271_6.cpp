#include <bits/stdc++.h>
using namespace std;
const int MN = 4011;
const int MQ = 30111;
struct Item {
  int cost, value, time;
} items[MN];
int nItem;
bool operator<(const Item& a, const Item& b) {
  if (a.time != b.time) return a.time < b.time;
  if (a.cost != b.cost) return a.cost < b.cost;
  return a.value < b.value;
}
struct Query {
  int time, value;
  int res;
} queries[MQ];
int nQuery;
vector<int> queryAt[MQ];
int p, f[MN][MN], g[MN][MN];
void init() {
  for (int i = 0, _a = (MQ); i < _a; i++) queryAt[i].clear();
}
void update(int& x, int val) {
  if (x < 0)
    x = val;
  else
    x = max(x, val);
}
int main() {
  ios ::sync_with_stdio(false);
  cout << (fixed) << setprecision(9);
  while (cin >> nItem >> p) {
    init();
    for (int i = (1), _b = (nItem); i <= _b; i++)
      cin >> items[i].cost >> items[i].value >> items[i].time;
    sort(items + 1, items + nItem + 1);
    cin >> nQuery;
    for (int i = (1), _b = (nQuery); i <= _b; i++) {
      cin >> queries[i].time >> queries[i].value;
      queryAt[queries[i].time].push_back(i);
    }
    vector<int> prev, cur;
    for (int time = p; time <= 20000 + p; time += p) {
      int from = time - p + 1, to = time;
      cur.clear();
      for (int i = (1), _b = (nItem); i <= _b; i++)
        if (from <= items[i].time && items[i].time <= to) {
          cur.push_back(i);
        }
      for (int i = (0), _b = (cur.size()); i <= _b; i++)
        memset(f[i], -1, sizeof f[i]);
      for (int i = (0), _b = (prev.size()); i <= _b; i++)
        memset(g[i], -1, sizeof g[i]);
      f[0][0] = 0;
      for (int i = (0), _b = (cur.size() - 1); i <= _b; i++)
        for (int j = (0), _b = (4000); j <= _b; j++)
          if (f[i][j] >= 0) {
            update(f[i + 1][j], f[i][j]);
            if (j + items[cur[i]].cost <= 4000)
              update(f[i + 1][j + items[cur[i]].cost],
                     f[i][j] + items[cur[i]].value);
          }
      g[0][0] = 0;
      for (int i = (0), _b = (prev.size() - 1); i <= _b; i++)
        for (int j = (0), _b = (4000); j <= _b; j++)
          if (g[i][j] >= 0) {
            update(g[i + 1][j], g[i][j]);
            if (j + items[prev[i]].cost <= 4000)
              update(g[i + 1][j + items[prev[i]].cost],
                     g[i][j] + items[prev[i]].value);
          }
      for (int i = (0), _b = (cur.size()); i <= _b; i++)
        for (int j = (1), _b = (4000); j <= _b; j++)
          f[i][j] = max(f[i][j], f[i][j - 1]);
      for (int i = (0), _b = (prev.size()); i <= _b; i++)
        for (int j = (1), _b = (4000); j <= _b; j++)
          g[i][j] = max(g[i][j], g[i][j - 1]);
      for (int t = (from), _b = (to); t <= _b; t++) {
        for (int id : queryAt[t]) {
          int nCur = 0;
          while (nCur < cur.size() && items[cur[nCur]].time <= queries[id].time)
            ++nCur;
          int nPrev = 0;
          while (nPrev < prev.size() &&
                 items[prev[nPrev]].time >= queries[id].time - p + 1)
            ++nPrev;
          int res = 0;
          for (int left = (0), _b = (queries[id].value); left <= _b; left++)
            res = max(res, f[nCur][left] + g[nPrev][queries[id].value - left]);
          queries[id].res = res;
        }
      }
      prev = cur;
      reverse(prev.begin(), prev.end());
    }
    for (int i = (1), _b = (nQuery); i <= _b; i++)
      cout << queries[i].res << "\n";
  }
  return 0;
}
