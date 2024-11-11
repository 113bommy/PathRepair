#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 4e5 + 100;
int a[N];
int ans[N];
vector<int> e[N];
int diver = 1;
void dfs_calc(int v, int p, int cnt) {
  if (a[v] % diver) cnt++;
  if (cnt >= 2) return;
  ans[v] = max(ans[v], diver);
  for (auto to : e[v]) {
    if (to == p) continue;
    dfs_calc(to, v, cnt);
  }
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void dfs_corner(int v, int p, int g) {
  if (v) {
    g = gcd(g, a[v]);
  }
  ans[v] = max(ans[v], g);
  for (auto to : e[v]) {
    if (to == p) continue;
    dfs_calc(to, v, g);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) ans[i] = 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  ans[0] = a[0];
  for (int i = 2; i <= a[0]; i++) {
    if (a[0] % i) continue;
    diver = i;
    dfs_calc(0, -1, 0);
  }
  dfs_corner(0, -1, 0);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
