#include <bits/stdc++.h>
using namespace std;
const int SIZE = 4e5 + 10;
vector<int> e[SIZE], emp;
int N, L, R, res[SIZE];
int d[SIZE], dn;
int bfs[SIZE], sons[SIZE];
int used[SIZE], tt, tt2, father[SIZE];
template <class T>
void maa(T& x, T y) {
  if (x < y) x = y;
}
template <class T>
void mii(T& x, T y) {
  if (x > y) x = y;
}
void build(int st, int given_v) {
  bfs[0] = st;
  tt2--;
  used[st] = tt2;
  int i = 0, j = 1;
  for (; i < j; i++) {
    int x = bfs[i];
    sons[x] = 1;
    for (int k = 0; k < (((int)(e[x]).size())); ++k) {
      int y = e[x][k];
      if (used[y] == tt || used[y] == tt2) continue;
      father[y] = x;
      used[y] = tt2;
      bfs[j++] = y;
    }
  }
  int num = j;
  for (i = j - 1; i >= 0; i--) {
    int x = bfs[i];
    if (sons[x] * 2 >= num) {
      res[x] = given_v;
      used[x] = tt;
      for (int k = 0; k < (((int)(e[x]).size())); ++k) {
        int y = e[x][k];
        if (used[y] != tt) build(y, given_v + 1);
      }
      return;
    }
    sons[father[x]] += sons[x];
  }
}
void init() {
  tt++;
  build(0, 1);
}
vector<int> edge[SIZE];
vector<pair<int, int> > edge_id;
int another[SIZE];
int polygon_id[SIZE];
int get_edge_id(int x, int y) {
  return lower_bound((edge_id).begin(), (edge_id).end(), make_pair(x, y)) -
         edge_id.begin();
}
int edge_used[SIZE];
vector<int> point_vector[SIZE];
int inc;
void get_polygon(int x, int y) {
  int my_id = get_edge_id(x, y);
  if (edge_used[my_id] >= 0) {
    return;
  }
  int your_id = another[my_id];
  if (edge_used[your_id] != -1) {
    e[edge_used[your_id]].push_back(inc);
    e[inc].push_back(edge_used[your_id]);
  }
  edge_used[my_id] = inc;
  point_vector[inc].push_back(x);
  int it = lower_bound((edge[y]).begin(), (edge[y]).end(), x) - edge[y].begin();
  it--;
  if (it < 0) it = ((int)(edge[y]).size()) - 1;
  get_polygon(y, edge[y][it]);
}
bool compare(int x, int y) {
  int it = 0;
  while (it < ((int)(point_vector[x]).size()) &&
         it < ((int)(point_vector[y]).size())) {
    if (point_vector[x][it] != point_vector[y][it])
      return point_vector[x][it] < point_vector[y][it];
    it++;
  }
  return 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (!m) {
    return 0 * puts("1");
  }
  tt++;
  memset((edge_used), -1, sizeof((edge_used)));
  for (int i = 0; i < (m); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    edge_id.push_back(make_pair(x, y));
    edge_id.push_back(make_pair(y, x));
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  for (int i = 0; i < (n); ++i) {
    int x = i;
    int y = (i + 1) % n;
    edge_id.push_back(make_pair(x, y));
    edge_id.push_back(make_pair(y, x));
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  sort((edge_id).begin(), (edge_id).end());
  for (int i = 0; i < (((int)(edge_id).size())); ++i) {
    another[i] = get_edge_id(edge_id[i].second, edge_id[i].first);
  }
  for (int i = 0; i < (n); ++i) {
    sort((edge[i]).begin(), (edge[i]).end());
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (((int)(edge[i]).size())); ++j) {
      if ((edge[i][j] + n - i) % n == n - 1) continue;
      if (edge_used[get_edge_id(i, edge[i][j])] >= 0) continue;
      get_polygon(i, edge[i][j]);
      sort((point_vector[inc]).begin(), (point_vector[inc]).end());
      reverse((point_vector[inc]).begin(), (point_vector[inc]).end());
      inc++;
    }
  }
  init();
  vector<int> ker;
  for (int i = 0; i < (m + 1); ++i) ker.push_back(i);
  sort((ker).begin(), (ker).end(), compare);
  for (int i = 0; i < (m + 1); ++i) printf("%d ", res[ker[i]]);
  return 0;
}
