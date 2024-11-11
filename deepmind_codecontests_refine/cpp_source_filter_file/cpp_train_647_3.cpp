#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    long long n, sum = 0, ans = 0, mx = INT_MIN;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = -30; i <= 30; i++) {
      sum = 0;
      for (long long j = 0; j < n; j++) {
        if (arr[j] <= i + 1)
          sum = max(1LL * 0, sum + arr[j]);
        else
          sum = 0;
        ans = max(ans, sum - i - 1);
      }
    }
    cout << ans << endl;
  }
}
