#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int gcd(int A, int B) {
  if (!B) return A;
  return gcd(B, A % B);
}
const int MAXN = 2e5 + 5;
long long int a[MAXN];
long long int b[MAXN];
long long int cnt[2];
long long int comp[MAXN];
vector<vector<int>> pos(MAXN);
vector<vector<pair<int, int>>> adj(MAXN);
vector<int> color(MAXN);
int co = 0;
void dfs(int v, int c) {
  color[v] = c;
  cnt[c]++;
  comp[v] = co;
  for (auto x : adj[v]) {
    int to = x.first;
    bool change = x.second;
    if (color[to] == -1) {
      color[to] = c ^ change;
      dfs(to, c ^ change);
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      pos[i].clear();
      color[i] = -1;
      comp[i] = -1;
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      pos[b[i]].push_back(i);
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++)
      if (pos[i].size() != 2) ok = 0;
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) {
      int c1 = pos[i][0];
      int c2 = pos[i][1];
      if (c1 == c2) continue;
      int r1 = a[c1] != i;
      int r2 = b[c2] != i;
      adj[c1 + 1].push_back({c2 + 1, r1 != r2});
      adj[c2 + 1].push_back({c1 + 1, r1 != r2});
    }
    long long int ans = 0;
    co = 0;
    vector<pair<int, int>> colcnt;
    for (int i = 1; i <= n; i++) {
      if (color[i] == -1) {
        cnt[0] = cnt[1] = 0;
        dfs(i, 0);
        ans += min(cnt[0], cnt[1]);
        colcnt.push_back({cnt[0], cnt[1]});
        co++;
      }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      if (color[i] ^ (colcnt[comp[i]].first < colcnt[comp[i]].second))
        cout << i << " ";
    }
    cout << '\n';
  }
}
