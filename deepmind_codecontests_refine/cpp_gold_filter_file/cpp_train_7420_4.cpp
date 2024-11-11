#include <bits/stdc++.h>
using namespace std;
const int MX = 1000 * 1000 + 7;
const int INF = 1e8 + 7;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
vector<int> edges[MX];
int LeftMatch[MX], RightMatch[MX];
int N, M;
int a[MX], b[MX];
bool visited[MX];
map<pair<int, int>, int> Map;
void clear() {
  memset(LeftMatch, -1, sizeof LeftMatch);
  memset(RightMatch, -1, sizeof RightMatch);
}
void input() { cin >> N >> M; }
void makeGraph() {
  int id = 0;
  for (__typeof(N) i = (1); i <= N; ++i)
    for (__typeof(M) j = (1); j <= M; ++j) {
      for (__typeof((8) - 1) k = (0); k <= (8) - 1; ++k) {
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
          if (Map.find(pair<int, int>(i, j)) == Map.end()) {
            Map[pair<int, int>(i, j)] = id++;
          }
          if (Map.find(pair<int, int>(nx, ny)) == Map.end()) {
            Map[pair<int, int>(nx, ny)] = id++;
          }
          edges[Map[pair<int, int>(nx, ny)]].push_back(
              Map[pair<int, int>(i, j)]);
        }
      }
    }
  N = id;
}
bool match(int u) {
  for (__typeof((edges[u]).end()) it = (edges[u]).begin();
       it != (edges[u]).end(); ++it) {
    int v = *it;
    if (visited[v]) continue;
    visited[v] = true;
    if (RightMatch[v] == -1 || match(RightMatch[v]) == true) {
      RightMatch[v] = u;
      LeftMatch[u] = v;
      return true;
    }
  }
  return false;
}
int bipartiteMatch() {
  int matching = 0;
  while (true) {
    memset(visited, false, sizeof visited);
    bool foundMatch = false;
    for (__typeof((N)-1) i = (0); i <= (N)-1; ++i) {
      if (LeftMatch[i] != -1) continue;
      if (match(i)) foundMatch = true, matching++;
    }
    if (foundMatch == false) break;
  }
  return matching;
}
int main() {
  clear();
  input();
  int r = N * M;
  if (N == 1 && M == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (N == 1 || M == 1) {
    printf("%d\n", r);
    return 0;
  }
  if (N == 2 || M == 2) {
    makeGraph();
    int ans = bipartiteMatch();
    printf("%d\n", r - ans / 2);
    return 0;
  }
  if (r % 2 == 0) {
    printf("%d\n", N * M / 2);
    return 0;
  } else
    printf("%d\n", (N * M + 1) / 2);
}
