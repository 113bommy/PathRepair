#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
map<int, int> mp;
set<int> G[200002];
int n, b[100002], c[100002], v[200002], t, a[200002], k;
void dfs(int x) {
  while (!G[x].empty()) {
    int p = *(G[x].begin());
    G[x].erase(G[x].begin());
    G[p].erase(G[p].find(x));
    dfs(p);
  }
  a[++t] = x;
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) cin >> b[i];
  for (int i = 1; i < n; i++) cin >> c[i];
  for (int i = 1; i < n; i++) {
    if (b[i] > c[i]) {
      cout << -1;
      return 0;
    }
    if (mp[b[i]] == 0) {
      mp[b[i]] = ++k;
      v[k] = b[i];
    }
    if (mp[c[i]] == 0) {
      mp[c[i]] = ++k;
      v[k] = c[i];
    }
  }
  for (int i = 1; i < n; i++) {
    G[mp[b[i]]].insert(mp[c[i]]);
    G[mp[c[i]]].insert(mp[b[i]]);
  }
  int nod = 1, bad = 0;
  for (int i = 1; i <= k; i++)
    if (G[i].size() % 2 == 1) {
      bad++;
      nod = i;
    }
  if (bad > 2) {
    cout << -1;
    return 0;
  }
  dfs(nod);
  if (t < n) {
    cout << -1;
    return 0;
  }
  for (int i = n; i >= 1; i--) cout << v[a[i]] << " ";
  return 0;
}
