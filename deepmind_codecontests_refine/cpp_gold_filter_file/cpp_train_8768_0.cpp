#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, lv[300009], vis[300009], sz[300009];
vector<int> e[300009];
void f(int nd) {
  vis[nd] = 1;
  for (auto j : e[nd])
    if (!vis[j]) lv[j] = lv[nd] + 1, f(j), sz[nd] += sz[j] + 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  f(1);
  for (int i = 1; i <= n; i++) lv[i] -= sz[i];
  sort(lv + 1, lv + 1 + n);
  for (int i = n; i > 0; i--)
    if (m > 0) ans += lv[i], m--;
  cout << ans;
}
