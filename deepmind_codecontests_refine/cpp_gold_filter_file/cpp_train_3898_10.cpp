#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 + 5;
vector<int> adj[N];
int H[N], p[N], l;
void dfs(int v, int par, int h) {
  ++H[h];
  l = max(l, h);
  for (int i = 0; i < (int)(adj[v]).size(); ++i)
    if (adj[v][i] != par) dfs(adj[v][i], v, h + 1);
}
int main() {
  ios::sync_with_stdio(false);
  int n, k, p, a, b, OK, Mk;
  cin >> n >> k >> p;
  if (!k) {
    cout << 0 << endl;
    return 0;
  }
  Mk = OK = k;
  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0, 1);
  for (int i = l; i > 1; --i) {
    for (int j = 0; j < H[i]; ++j) {
      p -= l - i;
      --k;
      while (p < 0) {
        k += H[l];
        --l;
        p += OK - k;
      }
      Mk = min(Mk, k);
      if (!k) {
        cout << OK << endl;
        return 0;
      }
    }
  }
  cout << OK - Mk << endl;
  return 0;
}
