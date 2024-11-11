#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n, k, cnt;
long long a[N], b[N];
bool check(long long y) {
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < y) {
      b[i] = 0;
      continue;
    }
    long long x = sqrt((a[i] - y) / 3.0);
    if (a[i] - 3 * (x + 1) * (x + 1) >= y) x++;
    x = min(x, a[i]);
    b[i] = x;
    cnt += x;
  }
  return cnt >= k;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long l = -3e18, r = 1e9, mid, ans;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  check(ans);
  for (int i = 1; i <= n && cnt > k; i++) {
    if (b[i] == 0) continue;
    if (a[i] - 3 * b[i] * b[i] == ans) {
      b[i]--;
      cnt--;
    }
  }
  for (int i = 1; i <= n; i++) cout << b[i] << " ";
  cout << endl;
  return 0;
}
