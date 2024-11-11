#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 2;
int deg[MAXN], out_deg[MAXN];
long long v_sol(int v) { return 1LL * out_deg[v] * (deg[v] - out_deg[v]); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj_list(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int mx = max(a, b), mn = min(a, b);
    adj_list[mn].push_back(mx);
    deg[mx]++;
    deg[mn]++;
    out_deg[mx]++;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += v_sol(i);
  }
  cout << ans << '\n';
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v;
    cin >> v;
    ans -= v_sol(v);
    out_deg[v] = deg[v];
    for (int j = 0; j < adj_list[v].size(); j++) {
      int w = adj_list[v][j];
      ans -= v_sol(w);
      adj_list[w].push_back(v);
      out_deg[w]--;
      ans += v_sol(w);
    }
    adj_list[v].clear();
    cout << ans << '\n';
  }
  return 0;
}
