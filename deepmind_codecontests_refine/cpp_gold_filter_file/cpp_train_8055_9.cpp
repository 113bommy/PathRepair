#include <bits/stdc++.h>
using namespace std;
long long const MAXN = 2e5 + 10;
long long const MAX = 1e9;
long long n, m, k;
long long a[MAXN], b[MAXN];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  long long pos = -1;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= m; i++) cin >> b[i];
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  for (long long i = 1; i <= n; i++) {
    if (a[i] > b[m - (n - i)]) return puts("YES"), 0;
  }
  cout << "NO";
  return 0;
}
