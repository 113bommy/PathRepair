#include <bits/stdc++.h>
using namespace std;
int sz = 800;
long long f[801][801];
int a[500001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1) {
      a[x] += y;
      for (int i = 1; i <= sz; i++) f[i][x % i] += y;
    } else {
      long long ans = 0;
      if (x > sz) {
        for (int i = y; i <= 500000; i += x) ans += a[i];
      } else
        ans = f[x][y];
      cout << ans << '\n';
    }
  }
}
