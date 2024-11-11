#include <bits/stdc++.h>
using namespace std;
int n = 0;
int x[132], y[132];
int q, c, a, b;
bool vis[132];
bool reach(int at, int t) {
  if (at == t) return true;
  if (vis[at]) return false;
  vis[at] = 1;
  for (int i = 0; i < n; i++) {
    if (x[i] < x[at] && x[at] < y[i] || x[i] < y[at] && y[at] < y[i])
      if (reach(i, t)) return true;
  }
  return false;
}
int main() {
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> c >> a >> b;
    if (c == 1) {
      x[n] = a;
      y[n] = b;
      n++;
    } else {
      memset(vis, 0, sizeof(vis));
      if (reach(a, b) == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
