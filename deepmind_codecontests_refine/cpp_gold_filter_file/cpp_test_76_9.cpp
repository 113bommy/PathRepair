#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int inf = 1e9 + 5;
long long int linf = 1ll * inf * inf;
const int maxn = 60;
bool adj[maxn][maxn];
vector<int> members;
int n, m;
inline bool check() {
  bool e = 1, k = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      int u = members[i];
      int v = members[j];
      if (adj[u][v])
        e = 0;
      else
        k = 0;
    }
  }
  if (e || k) {
    for (int i = 0; i < 5; i++) {
      cout << members[i] << " ";
    }
    exit(0);
  }
  return false;
}
bool comb(int i, int ndd) {
  if (i == n + 1) {
    if (check()) {
      return true;
    } else {
      return false;
    }
  }
  bool ok = 0;
  if (n - i + 1 != ndd) {
    if (comb(i + 1, ndd)) ok = 1;
  }
  if (ndd > 0) {
    members.push_back(i);
    if (comb(i + 1, ndd - 1)) ok = 1;
    members.pop_back();
  }
  return ok;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  n = min(n, 58);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (max(u, v) <= n) {
      adj[u][v] = 1;
      adj[v][u] = 1;
    }
  }
  if (!comb(1, 5)) {
    cout << -1;
  }
  return 0;
}
