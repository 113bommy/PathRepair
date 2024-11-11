#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 500005;
vector<int> gr[N], path, odd;
pair<int, int> ed[M];
bool us[M];
void GetEulerCircuit(int u) {
  while (true) {
    while (!gr[u].empty() && us[gr[u].back()]) {
      gr[u].pop_back();
    }
    if (gr[u].empty()) {
      break;
    }
    us[gr[u].back()] = true;
    int v = u ^ ed[gr[u].back()].first ^ ed[gr[u].back()].second;
    gr[u].pop_back();
    GetEulerCircuit(v);
  }
  path.push_back(u);
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    ed[i] = make_pair(u, v);
    gr[u].push_back(i);
    gr[v].push_back(i);
  }
  for (int u = 1; u <= n; u++) {
    if (gr[u].size() % 2) {
      odd.push_back(u);
    }
  }
  for (int i = 0; i < odd.size(); i += 2) {
    int u = odd[i], v = odd[i + 1];
    ed[m] = make_pair(u, v);
    gr[u].push_back(m);
    gr[v].push_back(m);
    m++;
  }
  if (m % 2) {
    ed[m] = make_pair(1, 1);
    gr[1].push_back(m);
    gr[1].push_back(m);
    m++;
  }
  GetEulerCircuit(1);
  for (int i = 0; i < m - 1; i++) {
    int u = path[i], v = path[i + 1];
    if (i % 2) {
      swap(u, v);
    }
    ed[i] = make_pair(u, v);
  }
  cout << m << "\n";
  for (int i = 0; i < m; i++) {
    int u = ed[i].first, v = ed[i].second;
    cout << u << " " << v << "\n";
  }
}
