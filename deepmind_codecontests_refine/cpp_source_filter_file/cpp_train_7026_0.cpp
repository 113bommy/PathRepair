#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const long long LINF = 1000000000000000000;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline void add(T& a, T b) {
  a = ((a + b) % MOD + MOD) % MOD;
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  vector<vector<int>> adj(n, vector<int>(n));
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
    adj[a[i]][b[i]] = 1;
    adj[b[i]][a[i]] = 1;
    deg[a[i]]++;
    deg[b[i]]++;
  }
  long long ans = LINF;
  for (int i = 0; i < m; i++) {
    int u = a[i], v = b[i];
    for (int j = 0; j < n; j++) {
      if (adj[u][i] == 1 && adj[v][i] == 1) {
        long long sum = deg[u] + deg[v] + deg[i] - 6;
        chmin(ans, sum);
      }
    }
  }
  if (ans == LINF) ans = -1;
  cout << ans << endl;
}
