#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, s1, s2, a[N];
bool check(int x) {
  int l = a[n] - x;
  int r = a[n] + x;
  for (int i = n - 1; i >= 1; --i) {
    if (l <= a[i] && a[i] <= r) {
      l = a[i] - x;
      r = a[i] + x;
    } else {
      l = max(a[i] - x, l);
      r = min(a[i] + x, r);
      if (l > r) return 0;
    }
  }
  return (l <= s1 && s1 <= r) || (l <= s2 && s2 <= r);
}
int main() {
  cin >> n >> s1 >> s2;
  if (s1 < s2) swap(s1, s2);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int l = s1 - s2, r = (int)1e9, ans;
  while (l <= r) {
    int mid = l + (r - l) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans;
  return 0;
}
