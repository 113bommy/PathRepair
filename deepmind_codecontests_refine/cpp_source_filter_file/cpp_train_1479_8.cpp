#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int INF = int(1e9), mod = 1000000007, N = int(1e5) + 5;
const long long BIG = 100000000000000;
const double PI = 3.141592653589793238463;
long long n, c[5][N], lol[5], check[N], comba[5];
long long ans = BIG;
vector<long long> vec[N], cols[5];
bool u[5];
void dfs(int v, int col, int p) {
  check[v] = col;
  cols[col].push_back(v);
  for (auto e : vec[v]) {
    if (p != e) dfs(e, col + 1 < 4 ? col + 1 : 1, v);
  }
}
void get(int v) {
  if (v > 3) {
    long long su = 0;
    for (auto e : cols[1]) {
      su += c[lol[1]][e];
    }
    for (auto e : cols[2]) {
      su += c[lol[2]][e];
    }
    for (auto e : cols[3]) {
      su += c[lol[3]][e];
    }
    if (ans > su) {
      ans = su;
      for (int i = 1; i <= 3; i++) {
        comba[i] = lol[i];
      }
    }
    return;
  }
  for (int i = 1; i <= 3; i++) {
    if (!u[i]) {
      u[i] = 1;
      lol[v] = i;
      get(v + 1);
      u[i] = 0;
      lol[v] = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[1][i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[2][i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[3][i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  int start = 1;
  for (int i = 1; i <= n; i++) {
    if (vec[i].size() > 2) {
      cout << -1;
      return 0;
    }
    if (vec[i].size() == 1) {
      start = i;
    }
  }
  dfs(start, 1, 0);
  get(1);
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    cout << comba[check[i]] << " ";
  }
}
