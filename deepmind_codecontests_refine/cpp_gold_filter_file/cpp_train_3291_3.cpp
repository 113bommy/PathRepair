#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const long long INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
long long rnd(long long x, long long y) {
  static uniform_int_distribution<long long> d;
  return d(tw) % (y - x + 1) + x;
}
const int MAXN = 65, MAXM = 35, SZ = 2005;
tuple<int, int, int> from[MAXM][MAXN][SZ];
int dist[MAXM][MAXN][SZ];
int calc(int a, int b, int c) { return b - a + c; }
int main() {
  cerr << fixed << setprecision(15);
  cout << fixed << setprecision(15);
  int m;
  scanf("%d", &m);
  vector<int> inp;
  for (int i = 0; i < m; ++i) {
    int num;
    scanf("%d", &num);
    inp.push_back(num);
  }
  sort(begin(inp), end(inp));
  tuple<int, int, int> pos = {-1, -1, -1};
  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  memset(dist, 127, sizeof dist);
  dist[0][0][0] = 0;
  while (((int)(q).size())) {
    int i, j, k;
    tie(i, j, k) = q.front();
    q.pop();
    if (i == m) {
      if (k == 0) {
        pos = {i, j, k};
        break;
      }
      continue;
    }
    int tmp = calc(j, k, inp[i]);
    if (tmp >= 0 && dist[i + 1][j + 1][tmp] > dist[i][j][k] + 1) {
      dist[i + 1][j + 1][tmp] = dist[i][j][k] + 1;
      from[i + 1][j + 1][tmp] = {i, j, k};
      q.push({i + 1, j + 1, tmp});
    }
    if (tmp >= 0 && dist[i][j + 1][tmp] > dist[i][j][k] + 1) {
      dist[i][j + 1][tmp] = dist[i][j][k] + 1;
      from[i][j + 1][tmp] = {i, j, k};
      q.push({i, j + 1, tmp});
    }
  }
  if (get<0>(pos) == -1) {
    cout << "=(\n";
    return 0;
  }
  vector<int> d;
  while (get<1>(pos) != 0) {
    int i, j, k;
    tie(i, j, k) = pos;
    d.push_back(inp[get<0>(from[i][j][k])]);
    pos = from[i][j][k];
  }
  reverse(begin(d), end(d));
  vector<vector<bool>> ans(((int)(d).size()), vector<bool>(((int)(d).size())));
  for (int i = 0; i < ((int)(d).size()); ++i) {
    set<pair<int, int>> now;
    for (int j = 0; j < i; ++j) {
      if (d[j]) {
        now.insert({d[j], j});
      }
    }
    for (int j = 0; j < i; ++j) {
      if (((int)(now).size())) {
        pair<int, int> tmp = *--now.end();
        if (tmp.first > d[i]) {
          ans[tmp.second][i] = 1;
          d[tmp.second]--;
          now.erase(--now.end());
        } else {
          --d[i];
          continue;
        }
      } else {
        --d[i];
      }
    }
    for (int j = 0; j < i; ++j) {
      if (!ans[j][i] && !ans[i][j]) {
        ans[i][j] = 1;
      }
    }
  }
  cout << ((int)(d).size()) << "\n";
  for (int i = 0; i < ((int)(d).size()); ++i) {
    for (int j = 0; j < ((int)(d).size()); ++j) {
      assert(i == j || (ans[i][j] ^ ans[j][i]));
      cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}
