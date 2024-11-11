#include <bits/stdc++.h>
using namespace std;
int cost[100005];
int vertex[100005];
int visit[100005];
int color[100005];
int ok = 1;
struct edge {
  int to, co;
};
bool dfs(int, int, int);
vector<edge> graph[100005];
int main(void) {
  memset(color, -1, sizeof(color));
  memset(vertex, -1, sizeof(vertex));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> cost[i];
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    for (int j = 0; j < num; j++) {
      int num1;
      cin >> num1;
      if (vertex[num1] != -1) {
        struct edge temp;
        temp.to = vertex[num1];
        temp.co = cost[num1];
        graph[i].push_back(temp);
        temp.to = i;
        temp.co = cost[num1];
        graph[(vertex[num1])].push_back(temp);
      } else
        vertex[num1] = i;
    }
  }
  for (int i = 0; i < m; i++) dfs(i, m, n);
  if (ok)
    cout << "YES";
  else
    cout << "NO";
}
bool dfs(int i, int m, int n) {
  if (ok == 0) return false;
  if (visit[i] == 0) color[i] = 0;
  visit[i] = 1;
  for (int j = 0; j < graph[i].size(); j++) {
    if (visit[graph[i][j].to] == 0) {
      if (graph[i][j].co == 0)
        color[graph[i][j].to] = color[i];
      else
        color[graph[i][j].to] = 1 - color[i];
      visit[graph[i][j].to] = 1;
      dfs(graph[i][j].to, m, n);
    } else {
      if (graph[i][j].co == 0) {
        if (color[graph[i][j].to] != color[i]) {
          ok = 0;
          return false;
        }
      } else {
        if (color[graph[i][j].to] != 1 - color[i]) {
          ok = 0;
          return false;
        }
      }
    }
  }
  return true;
}
