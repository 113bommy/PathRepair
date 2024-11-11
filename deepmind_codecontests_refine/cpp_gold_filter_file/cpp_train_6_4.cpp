#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 25;
int a[N], b[N], c[N], cycsz;
vector<int> g[N], cyc[N];
void dfs(int v) {
  while (!g[v].empty()) {
    int u = g[v].back();
    g[v].pop_back();
    dfs(a[u]);
    cyc[cycsz].push_back(u);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  memcpy(c, b, sizeof(int) * n);
  int sz = unique(c, c + n) - c;
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(c, c + sz, a[i]) - c;
    b[i] = lower_bound(c, c + sz, b[i]) - c;
    if (a[i] == b[i]) continue;
    g[b[i]].push_back(i);
  }
  cycsz = 0;
  for (int i = 0; i < sz; i++) {
    if (g[i].empty()) continue;
    dfs(i);
    cycsz++;
  }
  int sum = 0;
  for (int i = 0; i < cycsz; i++) {
    sum += cyc[i].size();
    reverse(cyc[i].begin(), cyc[i].end());
  }
  if (sum > s) {
    cout << -1 << '\n';
    exit(0);
  }
  int x = min(cycsz, s - sum);
  vector<vector<int> > ans;
  if (x) {
    vector<int> perm1, perm2;
    for (int i = 0; i < x; i++) {
      for (auto y : cyc[i]) {
        perm1.push_back(y);
      }
      perm2.push_back(cyc[i][0]);
    }
    reverse(perm2.begin(), perm2.end());
    ans.push_back(perm1);
    if (x > 1) ans.push_back(perm2);
  }
  for (int i = x; i < cycsz; i++) {
    ans.push_back(cyc[i]);
  }
  cout << ans.size() << '\n';
  for (auto vec : ans) {
    cout << vec.size() << '\n';
    for (auto y : vec) {
      cout << y + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}
