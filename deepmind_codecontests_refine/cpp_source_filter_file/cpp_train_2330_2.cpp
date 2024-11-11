#include <bits/stdc++.h>
long long int a[1000005], c[1000005];
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, t, ans = 0, sum = 0, j = 0;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum <= t)
    cout << n << endl;
  else {
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum < t)
        ans++;
      else {
        sum -= a[j];
        j++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
