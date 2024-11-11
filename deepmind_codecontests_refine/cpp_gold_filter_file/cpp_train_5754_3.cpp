#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long maxn = 1e6 + 100;
long long n, m, k, t;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long q, w, e, a, b, c;
  cin >> t;
  for (e = 0; e < t; e++) {
    cin >> n >> k >> m;
    vector<long long> A(n);
    long long allans = 0;
    for (q = 0; q < n; q++) {
      cin >> A[q];
    }
    for (w = 0; w <= m && k - 2 * w >= 0; w++) {
      long long ans = 0, mx = 0;
      for (q = 0; q <= k - 2 * w; q++) {
        ans += A[q];
      }
      for (q = 0; q <= k - 2 * w; q++) {
        mx = max(mx, A[q] + A[q + 1]);
      }
      ans += mx * w;
      allans = max(allans, ans);
    }
    cout << allans << endl;
  }
  return 0;
}
