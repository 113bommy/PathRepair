#include <bits/stdc++.h>
using namespace std;
long long int a[100000];
long long int n;
bool check(long long int rn) {
  long long int flag = 1;
  long long int sp = 0;
  for (long long int i = 0; i < n; i++) {
    sp += (rn - a[i]);
  }
  if (sp >= rn) return true;
  return false;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long int low = a[n - 1], high = 1e14 + 10;
  long long int ans;
  while (low <= high) {
    long long int mid = (low + high) / 2;
    if (check(mid)) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  cout << ans;
}
