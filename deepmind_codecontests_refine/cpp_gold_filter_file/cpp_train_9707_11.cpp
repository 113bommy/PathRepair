#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const long long INF = (long long)4e18;
int n;
long long k;
long long a[1 + N], b[1 + N];
bool check(long long d) {
  for (int i = 1; i <= n; i++) {
    if (a[i] <= d) {
      b[i] = 0;
    } else {
      b[i] = 1ll * sqrtl((long double)(a[i] - d) / 3);
      while (b[i] > 0 && a[i] - 3 * b[i] * b[i] < d) b[i]--;
      while (a[i] - 3 * b[i] * b[i] > d) b[i]++;
      b[i] = min(b[i], a[i]);
    }
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) sum += b[i];
  return sum <= k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long l = -INF, r = INF;
  long long best = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      best = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  check(best);
  for (int i = 1; i <= n; i++) k -= b[i];
  int i = 1;
  while (i <= n && k > 0) {
    if (a[i] != b[i] && a[i] - 3 * b[i] * b[i] == best) b[i]++, k--;
    i++;
  }
  for (int i = 1; i <= n; i++) cout << b[i] << " ";
  cout << "\n";
  return 0;
}
