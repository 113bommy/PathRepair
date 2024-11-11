#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
int a[MAXN];
int solve(int n, int time, int k) {
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    if (time >= n * a[i]) {
      ans += n;
      if (i == k) {
        ans += n;
      }
      time -= n * a[i];
    } else {
      ans += time / a[i];
      if (i == k) {
        ans += time / a[i];
      }
      break;
    }
  }
  return ans;
}
int main(void) {
  int n, k, m;
  cin >> n >> k >> m;
  int num = 0;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    num += a[i];
  }
  sort(a + 1, a + 1 + k);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (m > num * i) {
      ans = max(ans, solve(n - i, m - num * i, k) + i * (k + 1));
    } else
      break;
  }
  cout << ans;
  return 0;
}
