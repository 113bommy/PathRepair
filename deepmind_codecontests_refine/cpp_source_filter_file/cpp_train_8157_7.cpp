#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 7;
int edge[N][N];
int degree[N];
bool alive[N];
bool visited[N];
void dfs(int x) {
  if (visited[x]) return;
  visited[x] = 1;
  for (int next = (int)0; next < (int)n; next++)
    if (edge[x][next] and alive[next]) dfs(next);
}
bool is_connected(int next) {
  for (int i = (int)0; i < (int)n; i++) alive[i] = degree[i] > 0;
  memset(visited, 0, sizeof(visited));
  dfs(next);
  for (int i = (int)0; i < (int)n; i++)
    if (alive[i] and !visited[i]) return false;
  int nodd = 0;
  for (int i = (int)0; i < (int)n; i++)
    if (degree[i] % 2) nodd++;
  if (nodd != 0 and nodd != 2) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  vector<pair<pair<int, int>, int> > dominoes;
  n = 7;
  int m;
  cin >> m;
  for (int i = (int)0; i < (int)m; i++) {
    int a, b;
    cin >> a >> b;
    dominoes.push_back(make_pair(pair<int, int>(a, b), -1));
    edge[a][b]++, edge[b][a]++;
    degree[a]++, degree[b]++;
  }
  int nodd = 0;
  for (int i = (int)0; i < (int)n; i++)
    if (degree[i] % 2) nodd++;
  if (nodd != 0 and nodd != 2) {
    cout << "No solution\n";
    return 0;
  }
  vector<int> tour(m);
  int prev = -1;
  for (int i = (int)0; i < (int)n; i++)
    if (degree[i] % 2 == 1 and prev == -1) prev = i;
  for (int i = (int)0; i < (int)n; i++)
    if (degree[i] > 0 and prev == -1) prev = i;
  if (!is_connected(prev)) {
    cout << "No solution\n";
    return 0;
  }
  for (int i = (int)0; i < (int)m; i++) {
    for (int next = (int)0; next < (int)n; next++) {
      if (edge[prev][next] == 0) continue;
      edge[prev][next]--, edge[next][prev]--;
      degree[prev]--, degree[next]--;
      if (is_connected(next)) {
        for (int j = (int)0; j < (int)m; j++)
          if (dominoes[j].second == -1) {
            if (dominoes[j].first == pair<int, int>(prev, next)) {
              dominoes[j].second = 0;
              tour[i] = j;
              break;
            }
            if (dominoes[j].first == pair<int, int>(next, prev)) {
              dominoes[j].second = 1;
              tour[i] = j;
              break;
            }
          }
        prev = next;
        break;
      }
      edge[prev][next]++, edge[next][prev]--;
      degree[prev]++, degree[next]++;
    }
  }
  for (int i = (int)0; i < (int)m; i++)
    cout << (tour[i] + 1) << ' ' << (dominoes[tour[i]].second ? '-' : '+')
         << "\n";
  return 0;
}
