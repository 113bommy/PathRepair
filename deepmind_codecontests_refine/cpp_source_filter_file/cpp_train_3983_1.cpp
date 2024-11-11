#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15 + 42;
const long long MOD = 998244353;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  if (m > n) {
    cout << "0\n";
    return 0;
  }
  long long A[n], B[m];
  for (long long i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (long long i = 0; i < m; ++i) {
    cin >> B[i];
  }
  long long mn = INF;
  for (long long i = n - 1; i >= 0; --i) {
    mn = min(mn, A[i]);
  }
  if (mn < B[0]) {
    cout << "0\n";
    return 0;
  }
  mn = INF;
  long long j = m - 1;
  long long z = n - 1;
  long long res = 1;
  for (long long i = n - 1; i >= 0; --i) {
    if (A[i] < B[j]) {
      if (mn != B[j] || j == 0) {
        cout << "0\n";
        return 0;
      }
      res = res * (z - i) % MOD;
      --z;
      --j;
    }
    mn = min(mn, A[i]);
    if (mn != B[j]) {
      --z;
    }
  }
  if (j != 0) {
    cout << "0\n";
    return 0;
  }
  cout << res << "\n";
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}
