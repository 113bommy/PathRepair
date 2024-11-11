#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  int cnt = 0;
  long long ans = 0;
  int z = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      cnt++;
      ans += abs(a[i]) - 1;
    } else if (a[i] == 0)
      z++;
    else {
      ans += a[i] - 1;
    }
  }
  if (cnt % 2 == 0) {
    ans += z;
    cout << ans;
    return;
  }
  if (z == 0) {
    ans += 2;
    cout << ans;
    return;
  }
  ans += z;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    solve();
  }
  return 0;
}
