#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], ans, x, g;
bool used[10010];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m * 2; j++) {
      cin >> a[i];
      x++;
      if (a[i] == 1 && x <= 2 && !used[g]) {
        ans++;
        used[g] = true;
      }
      if (x == 2) {
        x = 0;
        g++;
      }
    }
  }
  cout << ans;
}
