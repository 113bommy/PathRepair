#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
inline void cmin(int &x, int y) {
  if (y < x) x = y;
}
inline void cmax(int &x, int y) {
  if (y > x) x = y;
}
int main() {
  long long n, k, m, a[100005];
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  long long sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i];
  long double mx = (long double)(sum + min(m, k * n)) / (long double)(n);
  for (int i = 1; i <= min(m, n - 1); i++) {
    sum -= a[i];
    long long t = sum + min(m - i, (n - i) * k);
    mx = max(mx, (long double)(t) / (long double)(n - i));
  }
  cout << fixed << setprecision(20) << mx << endl;
  return 0;
}
