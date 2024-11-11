#include <bits/stdc++.h>
using namespace std;
long long n, k;
int a[111111];
int b[111111];
bool check(long long num, long long power) {
  for (int i = 1; i <= n; i++) {
    if (num * a[i] - b[i] >= 0) power -= a[i] * num - b[i];
    if (power < 0) return false;
  }
  return true;
}
int solve(long long left, long long right) {
  long long mid;
  int ans = 0;
  while (left < right) {
    mid = (left + right) >> 1;
    if (check(mid, k)) {
      ans = mid;
      left = mid + 1;
    } else
      right = mid;
  }
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int ans = solve(1, 2000000002);
  cout << ans << endl;
  return 0;
}
