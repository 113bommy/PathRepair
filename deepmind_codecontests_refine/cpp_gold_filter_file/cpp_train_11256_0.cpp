#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 100, BLOCK_SIZE = 448, NN = 2e5 + 100;
long long n;
long double m, res;
string s;
vector<vector<long long>> g;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  g.resize(n + 1);
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (long long i = 1; i <= n; i++)
    if ((int)g[i].size() == 1) res += 1.0;
  cout << setprecision(13) << fixed << (2 * m) / res << "\n";
}
