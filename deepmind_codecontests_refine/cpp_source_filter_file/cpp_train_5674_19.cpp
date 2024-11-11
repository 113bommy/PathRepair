#include <bits/stdc++.h>
using namespace std;
int n, m, maxim, im, ans, x, viz[105];
int main() {
  cin >> n >> m;
  swap(n, m);
  for (int i = 1; i <= n; i++) {
    maxim = 0;
    for (int j = 1; j <= m; j++) {
      cin >> x;
      if (x > maxim) {
        maxim = x;
        im = j;
      }
    }
    viz[im]++;
  }
  maxim = 0;
  for (int i = 1; i <= m; ++i) {
    if (viz[i] > maxim) {
      maxim = viz[i];
      ans = i;
    }
  }
  cout << ans;
}
