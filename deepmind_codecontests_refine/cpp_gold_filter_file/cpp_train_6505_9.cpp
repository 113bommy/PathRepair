#include <bits/stdc++.h>
using namespace std;
long long n, m, arr[100005], temp[100005], ans;
int check(long long t) {
  for (int i = 1; i <= n; i++) temp[i] = arr[i];
  long long i = 0, j = 1, tl = t, p = 0;
  while (i < m && j <= n) {
    if (tl > 0) {
      tl -= min(tl, (j - p));
      p = j;
      long long k = min(tl, temp[j]);
      tl -= k;
      temp[j] -= k;
      if (temp[j] == 0) j++;
    } else {
      i++;
      tl = t;
      p = 0;
    }
  }
  for (int i = 1; i <= n; i++)
    if (temp[i] != 0) return 0;
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  long long l = 0, r = 1000000000000000;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
}
