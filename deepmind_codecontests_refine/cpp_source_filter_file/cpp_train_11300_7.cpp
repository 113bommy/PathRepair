#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int level[MAXN];
bool visit[MAXN];
vector<int> adj[MAXN];
void intialise() {
  for (int i = 0; i < MAXN; i++) level[i] = visit[i] = 0;
}
void bfs(int start) {
  queue<int> q;
  q.push(start);
  visit[start] = 0;
  level[start] = 1;
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    for (int i = 0; i < adj[p].size(); i++) {
      if (visit[adj[p][i]] == false) {
        visit[adj[p][i]] = true;
        level[adj[p][i]] = level[p] + 1;
        q.push(adj[p][i]);
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  while (m--) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  bfs(1);
  int max1 = 0;
  int j;
  for (int i = 1; i < MAXN; i++) {
    if (level[i] > max1) {
      j = i;
      max1 = max(max1, level[i]);
    }
  }
  intialise();
  bfs(j);
  for (int i = 0; i < MAXN; i++) {
    if (level[i] > max1) {
      j = i;
      max1 = max(max1, level[i]);
    }
  }
  cout << max1 - 1 << endl;
  return 0;
}
