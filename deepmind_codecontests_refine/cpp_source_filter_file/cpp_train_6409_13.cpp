#include <bits/stdc++.h>
using namespace std;
const int MAX_M = 100 + 2 * 10e5;
long long a[MAX_M], b[MAX_M], c[MAX_M], d[MAX_M];
long long n, m, k, x, s;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  cin >> x >> s;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= k; i++) cin >> c[i];
  for (int i = 1; i <= k; i++) cin >> d[i];
  long long ans = x * n;
  a[0] = x;
  c[0] = 0;
  for (int i = 1; i <= m; i++) {
    if (b[i] > s) continue;
    long long loc = 0;
    loc = upper_bound(d + 1, d + 1 + k, s - b[i]) - d;
    loc--;
    if (n < c[loc])
      ans = 0;
    else
      ans = min(ans, a[i] * (n - c[loc]));
  }
  cout << ans << endl;
  return 0;
}
