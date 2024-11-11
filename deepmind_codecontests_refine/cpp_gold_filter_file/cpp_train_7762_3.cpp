#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long c[1010];
vector<vector<long long> > x;
vector<long long> dd, yy;
long long sol = 0;
long long totk = 0;
long long totnode = 0;
bool used[1010];
bool isk[1010];
long long totww = 0;
void dfs(int v) {
  used[v] = 1;
  totk++;
  if (isk[v]) totnode++;
  totww += x[v].size();
  for (int i = 0; i < x[v].size(); i++) {
    if (!used[x[v][i]]) {
      dfs(x[v][i]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  x.resize(n + 2);
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    isk[c[i]] = 1;
  }
  for (int i = 0; i < m; i++) {
    long long u, v;
    cin >> v >> u;
    x[v].push_back(u);
    x[u].push_back(v);
  }
  long long ttt = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      totk = 0;
      totnode = 0;
      totww = 0;
      dfs(i);
      long long p = totk * (totk - 1);
      totww /= 2;
      p /= 2;
      sol += (p - totww);
      if (totnode > 0)
        yy.push_back(totk);
      else {
        dd.push_back(totk);
        ttt += totk;
      }
    }
  }
  sort(yy.rbegin(), yy.rend());
  long long vv = yy[0];
  long long g = 0;
  g += (vv * ttt);
  ttt += vv;
  for (int i = 0; i < dd.size(); i++) {
    long long mb = ttt - dd[i];
    g += (mb * dd[i]);
  }
  g /= 2;
  sol += g;
  cout << sol << endl;
}
