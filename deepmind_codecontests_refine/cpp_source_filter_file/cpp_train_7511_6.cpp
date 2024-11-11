#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  while (test--) {
    long long n, k, maxa = 0, ptr = -1;
    cin >> n >> k;
    long long aa[n], dp[n];
    for (long long i = 0; i < n; i++) {
      cin >> aa[i];
      if (aa[i] > maxa) {
        maxa = aa[i];
        ptr = i;
      }
      dp[i] = maxa;
    }
    long long re[n - 1];
    long long val = aa[0];
    for (long long i = 1; i < n; i++) {
      if (val > aa[i])
        re[i - 1] = aa[i];
      else {
        re[i - 1] = val;
        val = aa[i];
      }
    }
    for (long long i = 0; i < k; i++) {
      long long temp;
      cin >> temp;
      if (temp < ptr)
        cout << dp[temp - 1] << " " << aa[temp] << "\n";
      else
        cout << aa[ptr] << " " << re[(temp - 1) % (n - 1)] << "\n";
    }
  }
}
