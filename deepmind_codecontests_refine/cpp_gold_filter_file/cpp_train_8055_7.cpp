#include <bits/stdc++.h>
using namespace std;
const long long N = (int)1e5 + 7, inf = 1000000007LL;
int n, m, k, ans[N], vis[N], cnt, a[N], b[N];
int main() {
  ios_base ::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  reverse(a + 1, a + 1 + n);
  reverse(b + 1, b + 1 + m);
  if (n > m) {
    cout << "YES\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > b[i]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
