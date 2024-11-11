#include <bits/stdc++.h>
using namespace std;
const int MAXn = 1e5 + 10;

int indeg[MAXn], par[MAXn], n, m;
vector<int> g[MAXn], vec;

void del(int v) {
  for (int i = 0; i < g[v].size(); i++) {
  	indeg[g[v][i]]--;
  	if (!indeg[g[v][i]]) {
      par[g[v][i]] = v + 1;
      vec.push_back(g[v][i]);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n - 1 + m; i++) {
    int v, u;
    cin >> v >> u;v--;u--;
    g[v].push_back(u);
    indeg[u]++;
  }
  for (int i = 0; i < n; i++)
    if (!indeg[i]) {
      vec.push_back(i);
      break;
    }
  for (int i = 0; i < vec.size(); i++)
    	del(vec[i]);
  for (int i = 0; i < n; i++)
    	cout << par[i] << '\n';
}