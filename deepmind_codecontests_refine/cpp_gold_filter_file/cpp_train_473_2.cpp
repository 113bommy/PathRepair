#include <bits/stdc++.h>
using namespace std;
int f[100001], g[100001], h[100001];
int n, cnt;
bool work() {
  cnt = -1;
  for (int i = 0; i < n; ++i) {
    if (g[i] != -1) {
      if (f[i] != i) return false;
    } else {
      if (g[f[i]] == -1) {
        g[i] = ++cnt;
        h[cnt] = f[i];
        g[f[i]] = cnt;
      } else {
        if (h[g[f[i]]] != f[i]) return false;
        h[g[f[i]]] = f[i];
        g[i] = g[f[i]];
      }
    }
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> f[i];
  for (int i = 0; i < n; ++i) --f[i];
  for (int i = 0; i < n; ++i) g[i] = h[i] = -1;
  if (work()) {
    cout << ++cnt << endl;
    for (int i = 0; i < n; ++i) cout << ++g[i] << ' ';
    cout << endl;
    for (int i = 0; i < cnt; ++i) cout << ++h[i] << ' ';
  } else
    cout << -1 << endl;
  return 0;
}
