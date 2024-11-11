#include <bits/stdc++.h>
using namespace std;
double const pi = 3.14159265358979;
int const MAXN = 2000000;
long long const MOD = 1000000007;
long long const INF = 1000000000000000000;
long long x, y;
vector<int> a[300000];
int deg[300000];
long long d[300000][2];
bool u[300000];
void dfs(int v) {
  u[v] = 1;
  long long res = 0;
  long long k = 0;
  int ch = 0;
  for (int i = 0; i < (int)(a[v].size()); i++) {
    if (!u[a[v][i]]) {
      ch++;
      dfs(a[v][i]);
      res += d[a[v][i]][0];
      k += d[a[v][i]][1];
    }
  }
  if (k <= 1) {
    d[v][0] = res;
    d[v][1] = k;
  } else {
    d[v][0] = res + k - 1;
    d[v][1] = 0;
  }
  if (ch == 0) {
    d[v][1] = 1;
  }
}
int main() {
  int n, l, r;
  cin >> n >> x >> y;
  for (int i = 0; i < (int)(n - 1); i++) {
    cin >> l >> r;
    l--;
    r--;
    deg[l]++;
    deg[r]++;
    a[l].push_back(r);
    a[r].push_back(l);
  }
  if (x >= y) {
    int cnt = 0;
    for (int i = 0; i < (int)(n); i++) {
      if (deg[i] > 1) {
        cnt++;
      }
    }
    if (cnt > 1) {
      cout << y * (n - 1);
    } else {
      cout << x + y * (n - 2);
    }
    exit(0);
  }
  dfs(0);
  cout << y * (d[0][0] + d[0][1] - 1) + x * (n - 1 - (d[0][0] + d[0][1] - 1));
  return 0;
}
