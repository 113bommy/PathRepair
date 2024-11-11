#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 22;
int n, m, a[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = n; i >= 1; i--) {
    m -= a[i];
    if (m <= 0) {
      cout << n - i + 1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
