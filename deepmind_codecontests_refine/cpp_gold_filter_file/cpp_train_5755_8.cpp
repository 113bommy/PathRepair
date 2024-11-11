#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e17;
const double pi = acos(-1.0);
const int maxn = 1e6 + 5;
long long kase;
int n, m, p;
int x, k, y, a[maxn], b[maxn], c[maxn];
void run() {
  cin >> x >> k;
  for (int i = 1; i <= x; i++) cin >> a[i];
  for (int i = 1; i <= x; i++) cin >> y;
  sort(a + 1, a + 1 + x);
  int l = 1, r = 0;
  for (l = 1; l <= x; l++) {
    b[l] = b[l - 1] - 1;
    while (r <= x && a[r] - a[l] <= k) {
      b[l]++;
      r++;
    }
  }
  for (int i = x; i; i--) c[i] = max(b[i], c[i + 1]);
  int ans = 0;
  for (int i = 1; i <= x; i++) {
    ans = max(ans, b[i] + c[i + b[i]]);
  }
  cout << ans << '\n';
  for (int i = 1; i <= x; i++) b[i] = c[i] = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> kase;
  while (kase--) run();
  return 0;
}
