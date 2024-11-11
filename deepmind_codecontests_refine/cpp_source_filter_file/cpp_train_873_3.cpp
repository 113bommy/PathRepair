#include <bits/stdc++.h>
using namespace std;
int n, a[3000], second = 0, k;
bool first(int x) {
  bool vis[20];
  memset(vis, 0, sizeof(vis));
  while (x) {
    vis[x % 10] = 1;
    x /= 10;
  }
  for (int i = 0, _n = (int)(k); i < _n; i++)
    if (!vis[i]) return 0;
  return 1;
}
int main() {
  cin >> n >> k;
  for (int i = 0, _n = (int)(n); i < _n; i++) {
    cin >> a[i];
    if (first(a[i])) second++;
  }
  cout << second;
  return 0;
}
