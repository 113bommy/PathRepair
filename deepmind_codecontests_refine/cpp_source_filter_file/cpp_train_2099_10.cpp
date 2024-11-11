#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
int basis[22];
bool vis[2 * 200005];
int ob[22];
void add(int x) {
  int o = x;
  for (int i = 19; i >= 0; i--) {
    if (((x >> i) & 1)) x ^= basis[i];
    if ((x & (1 << i))) {
      basis[i] = x;
      ob[i] = o;
      break;
    }
  }
}
bool check(int j) {
  memset(basis, 0, sizeof basis);
  for (int i = 1; i <= n; i++)
    if (a[i] < (1 << j)) add(a[i]);
  for (int i = j - 1; i >= 0; i--)
    if (!basis[i]) return 0;
  return 1;
}
void dfs(int x, int j) {
  vis[x] = 1;
  cout << x << " ";
  for (int i = 0; i <= j; i++)
    if (!vis[x ^ ob[i]]) dfs(x ^ ob[i], j);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int j = 19; j >= 0; j--) {
    if (check(j)) {
      cout << j << '\n';
      dfs(0, j);
      cout << '\n';
      break;
    }
  }
  return 0;
}
