#include <bits/stdc++.h>
using namespace std;
const int mxn = 2000;
int n, k;
int a[mxn], x[mxn], y[mxn], it[mxn], vis[mxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    it[i] = i;
  }
  vis[a[0] = max_element(x, x + n) - x] = 1;
  cout << a[0] + 1;
  for (int i = 1; i < n; i++) {
    char c;
    cin >> c;
    a[i] = *max_element(it, it + n, [&](int u, int v) {
      return vis[u] || vis[v]
                 ? vis[u]
                 : (c == 'L') == ((x[u] - x[v]) * (y[v] - y[a[i - 1]]) <
                                  (x[v] - x[a[i - 1]]) * (y[u] - y[v]));
    });
    vis[a[i]] = 1;
    cout << " " << a[i] + 1;
  }
  cout << '\n';
  return 0;
}
