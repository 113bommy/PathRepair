#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
const long long mod = 1000000007;
long long n, col[N], x, d[N][2];
vector<int> g[N];
void dfs(int v) {
  d[v][0] = 1;
  d[v][1] = 0;
  for (int i = 0; i < g[v].size(); i++) {
    x = g[v][i];
    dfs(x);
    d[v][1] = (d[v][1] * d[x][0]) % mod;
    d[v][1] = (d[v][1] + d[v][0] * d[x][1]) % mod;
    d[v][0] = (d[v][0] * d[x][0]) % mod;
  }
  if (col[v])
    d[v][1] = d[v][0];
  else
    d[v][0] += d[v][1];
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x;
    g[x].push_back(i);
  }
  for (int i = 0; i < n; i++) cin >> col[i];
  dfs(0);
  cout << d[0][1];
  return 0;
}
