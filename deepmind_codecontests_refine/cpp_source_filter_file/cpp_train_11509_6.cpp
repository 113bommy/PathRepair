#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
const int nax = 505;
int n;
char grid[nax][nax];
int cc[nax][nax];
int cc_size[nax * nax];
int when_added[nax * nax];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char EMPTY = '.';
bool inside(int x, int y) { return 0 <= min(x, y) && max(x, y) < n; }
void dfs(int x, int y, int which_cc) {
  cc[x][y] = which_cc;
  ++cc_size[which_cc];
  for (int i = 0; i < 4; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (inside(x2, y2) && grid[x2][y2] == EMPTY && cc[x2][y2] == 0)
      dfs(x2, y2, which_cc);
  }
}
void add(int x, int y, int& answer, int current_time) {
  if (inside(x, y) && grid[x][y] == EMPTY) {
    int id = cc[x][y];
    if (when_added[id] != current_time) {
      when_added[id] = current_time;
      answer += cc_size[id];
    }
  }
}
int main() {
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
  int how_many_cc = 0;
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < n; ++y)
      if (grid[x][y] == EMPTY && cc[x][y] == 0) dfs(x, y, ++how_many_cc);
  int cur_time = 1;
  int best_answer = 0;
  for (int y_low = 0; y_low + k <= n; ++y_low) {
    for (int x = 0; x < k; ++x)
      for (int y = y_low; y < y_low + k; ++y) --cc_size[cc[x][y]];
    for (int x_low = 0; x_low + k <= n; ++x_low) {
      int answer = k * k;
      for (int x = x_low; x < x_low + k; ++x) {
        add(x, y_low - 1, answer, cur_time);
        add(x, y_low + k, answer, cur_time);
      }
      for (int y = y_low; y < y_low + k; ++y) {
        add(x_low - 1, y, answer, cur_time);
        add(x_low + k, y, answer, cur_time);
      }
      ++cur_time;
      best_answer = max(best_answer, answer);
      if (x_low + k != n) {
        for (int y = y_low; y < y_low + k; ++y) {
          ++cc_size[cc[x_low][y]];
          --cc_size[cc[x_low + k][y]];
        }
      }
    }
    for (int x = n - k; x < n; ++x)
      for (int y = y_low; y < y_low + k; ++y) ++cc_size[cc[x][y]];
  }
  printf("%dn", best_answer);
  return 0;
}
