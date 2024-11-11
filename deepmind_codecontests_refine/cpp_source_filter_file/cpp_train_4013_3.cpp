#include <bits/stdc++.h>
using namespace std;
struct state {
  int t, r;
  pair<int, int> p;
};
const int N = 1111;
int n, m;
pair<int, int> theseus, minotaur;
char grid[N][N];
bool visited[N][N][4];
map<char, string> rot = {{'+', "++++"}, {'L', "LURD"}, {'U', "URDL"},
                         {'R', "RDLU"}, {'D', "DLUR"}, {'|', "|-|-"},
                         {'-', "-|-|"}, {'^', "^>v<"}, {'>', ">v<^"},
                         {'v', "v<^>"}, {'<', "<^>v"}, {'*', "****"}};
string dc1[] = {"+LRD|^", "+LRU->", "+URL|v", "+URD-<"};
string dc2[] = {"+URL|v", "+URD-<", "+LRD|^", "+LRU->"};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
  scanf("%d %d", &theseus.first, &theseus.second);
  --theseus.first;
  --theseus.second;
  scanf("%d %d", &minotaur.first, &minotaur.second);
  --minotaur.first;
  --minotaur.second;
  deque<state> q;
  q.push_back({0, 0, theseus});
  visited[theseus.first][theseus.second][0] = true;
  while (!q.empty()) {
    int t = q.front().t;
    int r = q.front().r;
    pair<int, int> p = q.front().p;
    q.pop_front();
    if (p == minotaur) {
      printf("%d\n", t);
      return;
    }
    if (grid[p.first][p.second] == '*') continue;
    int nr = (r + 1) % 4;
    if (!visited[p.first][p.second][nr]) {
      q.push_back({t + 1, nr, p});
      visited[p.first][p.second][nr] = true;
    }
    char c1 = grid[p.first][p.second];
    for (int d = 0; d < 4; ++d) {
      if (dc1[d].find(rot[c1][r]) == string::npos) continue;
      pair<int, int> np = {p.first + dx[d], p.second + dy[d]};
      if (np.first < 0 || np.first >= n || np.second < 0 || np.second >= m)
        continue;
      char c2 = grid[np.first][np.second];
      if (dc2[d].find(rot[c2][r]) == string::npos) continue;
      if (!visited[np.first][np.second][r]) {
        q.push_back({t + 1, r, np});
        visited[np.first][np.second][r] = true;
      }
    }
  }
  printf("%d\n", -1);
}
int main() {
  solve();
  return 0;
}
