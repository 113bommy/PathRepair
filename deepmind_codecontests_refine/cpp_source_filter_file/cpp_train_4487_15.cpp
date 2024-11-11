#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long llinf = (1LL << 61);
const int inf = (1 << 30);
const int nmax = 2e5 + 50;
const int mod = 1e9 + 7;
using namespace std;
int n, i;
long long a[nmax], x = llinf;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i <= 2 * n; i++) cin >> a[i];
  sort(a + 1, a + 2 * n + 1);
  if (n == 1) return cout << 0 << endl, 0;
  for (i = 2; i < n; i++) x = min(x, a[i + n - 1] - a[i]);
  cout << min((a[2 * n] - a[1]) * x, (a[n] - a[1]) * (a[2 * n] - a[n + 1]))
       << endl;
  return 0;
}
