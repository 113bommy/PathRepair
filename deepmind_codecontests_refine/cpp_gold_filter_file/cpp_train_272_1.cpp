#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
struct Where {
  int node;
  int parity;
  Where(int _node = 0, int _parity = 0) {
    node = _node;
    parity = _parity;
  }
};
vector<int> gr[MAXN];
vector<int> gri[MAXN];
bool inQ[MAXN];
int grad[MAXN];
bool found[MAXN][2];
int last[MAXN][2];
int vis[MAXN];
bool cycle = false;
void dfs(int node) {
  if (vis[node] == 1) cycle = 1;
  if (cycle || vis[node]) return;
  vis[node] = 1;
  for (auto x : gri[node]) dfs(x);
  vis[node] = 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  scanf("%d", &n);
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    while (x--) {
      int y;
      scanf("%d", &y);
      grad[i]++;
      gr[y].push_back(i);
      gri[i].push_back(y);
    }
  }
  int s;
  scanf("%d", &s);
  queue<Where> Q;
  for (int i = 1; i <= n; ++i) {
    if (grad[i] == 0) Q.push({i, 0});
  }
  if (Q.size() == 0) {
    cout << "Draw";
    return 0;
  }
  while (Q.size()) {
    Where current;
    current = Q.front();
    Q.pop();
    if (current.node == s && current.parity == 1) {
      break;
    }
    for (auto x : gr[current.node]) {
      if (found[x][current.parity ^ 1]) continue;
      found[x][current.parity ^ 1] = true;
      last[x][current.parity ^ 1] = current.node;
      Q.push({x, current.parity ^ 1});
    }
  }
  if (found[s][1]) {
    cout << "Win\n";
    int node = s;
    int parity = 1;
    cout << node << ' ';
    while (grad[node] != 0) {
      node = last[node][parity];
      parity ^= 1;
      cout << node << ' ';
    }
    return 0;
  }
  dfs(s);
  if (cycle)
    cout << "Draw";
  else
    cout << "Lose";
  return 0;
}
