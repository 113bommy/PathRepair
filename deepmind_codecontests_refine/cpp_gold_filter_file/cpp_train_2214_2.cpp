#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n + 1];
    for (long long int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long int ans = 0;
    vector<long long int> freq((n * n) + n + n, 0);
    for (long long int k = 2; k < n; k++) {
      long long int j = k - 1;
      for (long long int i = 1; i <= k - 2; i++) {
        freq[(n * a[i]) + a[j]]++;
      }
      for (long long int l = k + 1; l <= n; l++) {
        ans += freq[(n * a[k]) + a[l]];
      }
    }
    cout << ans << "\n";
  }
}
