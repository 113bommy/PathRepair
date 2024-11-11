#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
using Pli = pair<ll, int>;
const int inf = 1e9 + 10;
const int maxN = 2 * 1e5 + 10;
int n, m, q;
vector<Vi> adj;
vector<int> in, out;
void solve() {
  cin >> n >> m;
  adj.resize(n + 1);
  in.resize(n + 1);
  out.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    adj[a].push_back(b);
    in[a]++;
    out[b]++;
  }
  long long result = 0;
  for (int i = 1; i <= n; i++) {
    result += (ll)in[i] * out[i];
  }
  cout << result << "\n";
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    for (int v : adj[a]) {
      result -= out[a] + in[v];
      in[a]--;
      out[a]++;
      out[v]--;
      in[v]++;
      adj[v].push_back(a);
      result += in[a] + out[v];
    }
    adj[a].clear();
    cout << result << "\n";
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int z = 1;
  for (int i = 0; i < z; i++) {
    solve();
  }
  return 0;
}
