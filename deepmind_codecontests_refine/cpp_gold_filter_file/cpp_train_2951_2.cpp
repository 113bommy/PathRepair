#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795028841971l;
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
vector<int> e[100010];
vector<int> f[100010];
int c[100010];
int ans = 0;
void dfs(int v, int k) {
  if (c[v] != -1) {
    ans = gcd(ans, abs(c[v] - k));
    return;
  }
  c[v] = k;
  for (int i = 0; i < int(e[v].size()); i++) {
    dfs(e[v][i], k + 1);
  }
  for (int i = 0; i < int(f[v].size()); i++) {
    dfs(f[v][i], k - 1);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < int(m); i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    e[x].push_back(y);
    f[y].push_back(x);
  }
  memset(c, -1, sizeof c);
  for (int i = 0; i < int(n); i++) {
    if (c[i] == -1) {
      dfs(i, 1000000000);
    }
  }
  if (ans == 0) {
    ans = n;
  }
  cout << ans;
  return 0;
}
