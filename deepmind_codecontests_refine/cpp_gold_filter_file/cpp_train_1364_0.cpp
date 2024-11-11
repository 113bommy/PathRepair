#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
int a[N];
int c[N];
char clr[N];
bool cycle[N];
int ans = 0;
int dfs2(int v) {
  if (cycle[v]) return mod;
  cycle[v] = true;
  return min(c[v], dfs2(a[v]));
}
void dfs(int v) {
  if (clr[v] == 2) return;
  if (clr[v] == 1) {
    if (!cycle[v]) {
      ans += dfs2(v);
    }
    return;
  }
  clr[v] = 1;
  dfs(a[v]);
  clr[v] = 2;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    if (clr[i] == 0) {
      dfs(i);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
}
