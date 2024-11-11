#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long int i = 1, j = n - 1;
    long long int ans = 1, ans1 = a[0], ans2 = 0;
    long long int prev1 = a[0], prev2 = 0;
    while (i <= j) {
      ans++;
      if (ans % 2) {
        prev1 = 0;
        while (i <= j && prev1 <= prev2) {
          prev1 += a[i];
          i++;
        }
        ans1 += prev1;
      } else {
        prev2 = 0;
        while (i <= j && prev2 <= prev1) {
          prev2 += a[j];
          j--;
        }
        ans2 += prev2;
      }
    }
    cout << ans << " " << ans1 << " " << ans2 << '\n';
  }
}
