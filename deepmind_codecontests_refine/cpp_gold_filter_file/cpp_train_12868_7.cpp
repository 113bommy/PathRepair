#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18;
const long long mod = (long long)1e9 + 7;
const double pi = acos(-1.0);
const double eps = (double)1e-9;
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
const int N = 100500;
long long a[N], b[N], c[N], d[N], e[N];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    d[i] = max(a[i], d[i - 1] + 1);
    b[i] = b[i - 1] + d[i] - a[i];
  }
  for (int i = n; i >= 1; i--) {
    e[i] = max(e[i + 1] + 1, a[i]);
    c[i] = c[i + 1] + e[i] - a[i];
  }
  long long ans = inf;
  for (int i = 0; i <= n; i++) {
    long long cur = b[i] + c[i + 1];
    if (d[i] == e[i + 1]) cur++;
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
