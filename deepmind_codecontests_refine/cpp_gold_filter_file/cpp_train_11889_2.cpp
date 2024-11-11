#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)(4e5 + 7);
int q, n, p[MAXN], f[MAXN];
void go(int u, int pVal) {
  if (f[u] > 0) return;
  f[u] = pVal + 1;
  go(p[u], f[u]);
  f[u] = max(f[u], f[p[u]]);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    f[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] == 0) {
      go(i, 0);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << f[i] << " ";
  }
  cout << endl;
}
int main() {
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
