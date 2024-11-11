#include <bits/stdc++.h>
using namespace std;
vector<int> g[1005];
bool ch[1005];
int BFS(int s) {
  int i, j, u, v;
  queue<int> q;
  memset(ch, 0, sizeof ch);
  q.push(s);
  ch[s] = 1;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (i = 0; i < g[u].size(); i++) {
      v = g[u][i];
      if (!ch[v]) {
        ch[v] = 1;
        q.push(v);
      }
    }
  }
  return v;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    g[i].push_back(p);
  }
  for (int i = 1; i <= n; i++) {
    cout << BFS(i) << " ";
  }
}
