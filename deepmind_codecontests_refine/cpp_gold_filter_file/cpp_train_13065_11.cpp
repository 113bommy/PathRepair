#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, i, j, x, ans;
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a >> b;
      if (a + b > 0) ans++;
    }
  }
  cout << ans;
}
