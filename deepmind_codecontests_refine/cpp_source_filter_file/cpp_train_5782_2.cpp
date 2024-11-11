#include <bits/stdc++.h>
using namespace std;
const int kNmax = 3e5 + 5;
int n, m;
int bcc[kNmax];
int num_bcc;
int use[kNmax];
vector<int> g[kNmax];
vector<pair<int, int>> gt[kNmax];
int l[kNmax], r[kNmax], z[kNmax];
int depth[kNmax], lowlink[kNmax];
bool artifact[kNmax];
stack<int> s;
void dfs_bcc(int x, int f = 0) {
  depth[x] = depth[f] + 1;
  lowlink[x] = depth[x];
  use[x] = 1;
  s.push(x);
  for (int i : g[x]) {
    int y = x ^ l[i] ^ r[i];
    if (y == f) continue;
    if (use[y]) {
      lowlink[x] = min(lowlink[x], depth[y]);
    } else {
      dfs_bcc(y, x);
      lowlink[x] = min(lowlink[x], lowlink[y]);
    }
  }
  if (lowlink[x] != depth[x]) return;
  num_bcc++;
  while (s.top() != x) {
    bcc[s.top()] = num_bcc;
    s.pop();
  }
  bcc[x] = num_bcc;
  s.pop();
}
bool sol = 0;
void dfs_sol(int x, int end, int f = 0, bool ok = false) {
  ok |= artifact[x];
  if (end == x) {
    sol = ok;
    return;
  }
  for (const auto& [y, a] : gt[x]) {
    if (y == f) continue;
    dfs_sol(y, end, x, ok | a);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i] >> z[i];
    g[l[i]].push_back(i);
    g[r[i]].push_back(i);
  }
  dfs_bcc(1);
  for (int i = 1; i <= m; i++) {
    if (bcc[l[i]] == bcc[r[i]]) {
      artifact[bcc[l[i]]] = true;
      continue;
    }
    gt[bcc[l[i]]].emplace_back(bcc[r[i]], z[i]);
    gt[bcc[r[i]]].emplace_back(bcc[l[i]], z[i]);
  }
  int a, b;
  cin >> a >> b;
  dfs_sol(bcc[a], bcc[b]);
  cout << (sol ? "YES" : "NO") << '\n';
  return 0;
}
