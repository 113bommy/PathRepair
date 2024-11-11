#include <bits/stdc++.h>
using namespace std;
const int maxn = 528144;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
const long double pi = acos(-1);
const long double eps = 1e-6;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> used(3 * n, 0);
  vector<int> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (!used[u] && !used[v]) {
      used[u] = used[v] = 1;
      edges.push_back(i);
    }
  }
  if (edges.size() >= n) {
    cout << "Matching" << endl;
    for (int i = 0; i < n; i++) {
      cout << edges[i] + 1 << " ";
    }
    cout << endl;
  } else {
    vector<int> se;
    for (int i = 0; i < 3 * n; i++) {
      if (!used[i]) {
        se.push_back(i + 1);
      }
    }
    cout << "IndSet" << endl;
    for (int i = 0; i < n; i++) {
      cout << se[i] + 1 << " ";
    }
    cout << endl;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(10) << fixed;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) solve();
  return 0;
}
