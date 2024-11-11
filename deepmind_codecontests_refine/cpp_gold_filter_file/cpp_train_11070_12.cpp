#include <bits/stdc++.h>
using namespace std;
const long long MAX1 = 1000 * 1000 * 1000;
const long long MAX = MAX1 * MAX1;
const int maxn = 11 * 1000;
long long a[maxn], b[maxn];
int c;
bool check(int n) {
  int i;
  for ((i) = 0; (i) < (n); (i)++)
    if (a[i] != 0) return false;
  return true;
}
long long f(long long x, int n) {
  int i;
  long long ans = 0;
  for ((i) = 0; (i) < (n); (i)++) {
    ans += 1 + (a[i] * x) / b[i];
    if (ans > c) return MAX + 1;
  }
  return ans;
}
int main() {
  int n, i, j;
  long long up, low, mid, tmp, mx = 1;
  long long ans1, ans2;
  cin >> n >> c;
  for ((i) = 0; (i) < (n); (i)++) {
    cin >> a[i] >> b[i];
    if (a[i] > mx) mx = a[i];
  }
  if (check(n)) {
    if (c == n)
      cout << -1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  low = 0;
  up = MAX / mx + mx;
  while (low < up) {
    mid = (up + low - 1) / 2;
    tmp = f(mid, n);
    if (tmp >= c)
      up = mid;
    else
      low = mid + 1;
  }
  ans1 = low;
  if (ans1 == 0) ans1++;
  low = 0;
  up = MAX / mx + mx;
  while (low < up) {
    mid = (up + low + 1) / 2;
    tmp = f(mid, n);
    if (tmp > c)
      up = mid - 1;
    else
      low = mid;
  }
  ans2 = up;
  if (f(ans1, n) != c || ans2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (ans1 > ans2)
    cout << 0 << endl;
  else
    cout << ans2 - ans1 + 1 << endl;
  return 0;
}
