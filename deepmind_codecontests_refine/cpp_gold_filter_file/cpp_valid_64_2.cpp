#include <bits/stdc++.h>
using namespace std;
int parent[2][100002];
int findParent(int child, int par[]) {
  if (child == par[child]) return child;
  return par[child] = findParent(par[child], par);
}
void merge(int u, int v, int par[]) {
  int x = findParent(u, par);
  int y = findParent(v, par);
  if (x == y) return;
  par[y] = x;
}
bool cycleCheck(int u, int v, int par[]) {
  if (findParent(u, par) == findParent(v, par)) return true;
  return false;
}
void Set2Vector(set<int>& tmpset, vector<int>& tmpv) {
  for (auto k : tmpset) tmpv.push_back(k);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m[2];
  cin >> n >> m[0] >> m[1];
  for (int i = 0; i <= n; ++i) parent[0][i] = parent[1][i] = i;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < m[i]; ++j) {
      int x, y;
      cin >> x >> y;
      merge(x, y, parent[i]);
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) findParent(j, parent[i]);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; ++i) {
    if (cycleCheck(1, i, parent[0]) || cycleCheck(1, i, parent[1])) continue;
    ans.push_back({1, i});
    merge(1, i, parent[0]);
    merge(1, i, parent[1]);
  }
  vector<int> A;
  vector<int> B;
  for (int i = 1; i <= n; i++) {
    if (cycleCheck(i, 1, parent[0]) && !cycleCheck(i, 1, parent[1]) &&
        findParent(i, parent[1]) == i)
      A.push_back(i);
    if (cycleCheck(i, 1, parent[1]) && !cycleCheck(i, 1, parent[0]) &&
        findParent(i, parent[0]) == i)
      B.push_back(i);
  }
  int mini = std::min(A.size(), B.size());
  cout << (ans.size() + mini) << '\n';
  if (!ans.empty()) {
    for (auto x : ans) cout << x.first << ' ' << x.second << '\n';
  }
  for (int i = 0; i < mini; ++i) cout << A[i] << ' ' << B[i] << '\n';
}
