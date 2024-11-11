#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int INF = 1000000000;
const int maxn = 2000006;
int n, m;
vector<int> v[maxn];
bool flag[maxn];
bool inStack[maxn];
int color[maxn], low[maxn], dfn[maxn];
int dfsClock, sccCnt;
stack<int> s;
int dx[1000], dy[1000];
void tarjan(int u) {
  flag[u] = true;
  low[u] = dfn[u] = dfsClock++;
  s.push(u);
  inStack[u] = true;
  for (int x : v[u]) {
    if (!flag[x]) {
      tarjan(x);
      low[u] = min(low[u], low[x]);
    } else if (inStack[x])
      low[u] = min(low[u], dfn[x]);
  }
  if (low[u] == dfn[u]) {
    ++sccCnt;
    int z;
    do {
      z = s.top();
      s.pop();
      inStack[z] = false;
      color[z] = sccCnt;
    } while (z != u);
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> dx[i] >> dy[i];
    if (dx[i] > dy[i]) swap(dx[i], dy[i]);
    for (int j = 1; j < i; j++) {
      if (!(dx[i] == dx[j] || dx[i] == dy[j] || dy[i] == dx[j] ||
            dy[i] == dy[j] || dx[i] > dy[j] || dx[j] > dy[i] ||
            (dx[i] < dx[j] && dy[i] > dy[j]) ||
            (dx[j] < dx[i] && dy[j] > dy[i]))) {
        v[i].push_back(j + m);
        v[i + m].push_back(j);
        v[j].push_back(i + m);
        v[j + m].push_back(i);
      }
    }
  }
  for (int i = 1; i <= m * 2; i++)
    if (!flag[i]) tarjan(i);
  for (int i = 1; i <= m; i++) {
    if (color[i] == color[i + n]) {
      cout << "Impossible" << endl;
      return;
    }
  }
  for (int i = 1; i <= m; i++) cout << (color[i] < color[i + m] ? 'i' : 'o');
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
