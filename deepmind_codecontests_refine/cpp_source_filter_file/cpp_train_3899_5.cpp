#include <bits/stdc++.h>
using namespace std;
int g[3001];
int n, v, t, l;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> v;
  for (int i = 0, a, b; i < n; i++) {
    cin >> a >> b;
    g[a - 1] = b;
  }
  for (int i = 0; i < 3001; i++) {
    int r = v;
    if (l <= r) {
      t += l;
      r -= l;
    } else {
      t += r;
      r = 0;
    }
    if (g[i] <= r) {
      t += g[i];
      g[i] = 0;
    } else {
      t += r;
      g[i] -= r;
    }
    l = 0;
    if (g[i] > 0) {
      l = g[i];
    }
  }
  cout << t << "\n";
  return 0;
}
