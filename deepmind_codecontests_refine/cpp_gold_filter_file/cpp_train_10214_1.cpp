#include <bits/stdc++.h>
using namespace std;
map<int, int> sets;
int find_set(int u) { return sets[u] = (sets[u] == u) ? u : find_set(sets[u]); }
bool union_set(int u, int v) {
  int parentU = find_set(u);
  int parentV = find_set(v);
  if (parentU == parentV) return true;
  sets[parentV] = parentU;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, u, v, c = 0;
  cin >> n >> m;
  bool ok = true;
  ;
  for (int i = 1; i <= n; i++) sets[i] = i;
  while (m--) {
    cin >> u >> v;
    if (union_set(u, v)) {
      c++;
    }
  }
  int a = find_set(1);
  for (int i = 2; i <= n; i++) {
    if (find_set(i) != a) {
      ok = false;
      break;
    }
  }
  if (ok && c == 1) {
    cout << "FHTAGN!" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
