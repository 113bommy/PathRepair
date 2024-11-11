#include <bits/stdc++.h>
using namespace std;
template <typename T>
auto operator<<(ostream& out, T& container)
    -> decltype(container.begin(), container.end(), out) {
  bool first = true;
  out << "[";
  for (auto it = container.begin(); it != container.end(); ++it) {
    if (!first) out << ", ";
    out << *it;
    first = false;
  }
  return out << "]";
}
int n, m;
vector<pair<int, int>> e[100000];
bool usededge[100000];
bool isroot[100000];
int ind[100000], low[100000];
int counter = 0;
vector<int> res;
void tarjan(int u) {
  ind[u] = low[u] = counter++;
  vector<pair<int, int>> ne;
  for (auto a : e[u]) {
    int v = a.first;
    if (usededge[a.second]) continue;
    usededge[a.second] = true;
    ne.push_back(a);
    if (ind[v] == -1) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], ind[v]);
    }
  }
  e[u] = ne;
}
bool calc(int u, bool good) {
  vector<pair<int, int>> newstarts, continues, bridges;
  int back = -1;
  int backcount = 0;
  for (auto a : e[u]) {
    int v = a.first;
    if (ind[v] < ind[u]) {
      backcount++;
      back = a.second;
    } else {
      if (low[v] < ind[u])
        continues.push_back(a);
      else if (low[v] == ind[u])
        newstarts.push_back(a);
      else
        bridges.push_back(a);
    }
  }
  for (auto a : bridges) {
    int v = a.first;
    calc(v, true);
  }
  for (auto a : newstarts) {
    int v = a.first;
    if (calc(v, true)) res.push_back(a.second);
  }
  if (continues.size() == 0) {
    if (good && backcount == 1) {
      res.push_back(back);
      return true;
    } else
      return false;
  } else if (continues.size() + backcount == 1) {
    if (calc(continues[0].first, good)) {
      res.push_back(continues[0].second);
      return true;
    }
    return false;
  } else
    for (auto a : continues) {
      calc(a.first, false);
      return false;
    }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    e[a].push_back({b, i});
    e[b].push_back({a, i});
  }
  for (int i = 0; i < n; ++i) ind[i] = low[i] = -1;
  for (int i = 0; i < n; ++i) {
    if (ind[i] != -1) continue;
    isroot[i] = true;
    tarjan(i);
  }
  for (int i = 0; i < n; ++i) {
    if (!isroot[i]) continue;
    calc(i, true);
  }
  sort(res.begin(), res.end());
  cout << res.size() << "\n";
  for (int a : res) cout << a + 1 << " ";
  cout << "\n";
}
