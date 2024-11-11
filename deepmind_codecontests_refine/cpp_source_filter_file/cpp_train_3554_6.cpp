#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], c[N], vis[N];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = (1); i < (n + 1); i++) cin >> a[i];
  for (int i = (1); i < (k + 1); i++) b[i] = a[i];
  int task = 0, cur = k + 1, ans;
  while (task < n) {
    int q = task * 100.0 / n + 0.5;
    for (int i = 1; i <= k; ++i) {
      if (!b[i]) continue;
      c[i]++;
      if (c[i] == q && !vis[i]) ans++, vis[i] = 1;
      if (c[i] >= b[i]) {
        task++;
        vis[i] = 0;
        c[i] = 0;
        b[i] = a[cur];
        cur++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
