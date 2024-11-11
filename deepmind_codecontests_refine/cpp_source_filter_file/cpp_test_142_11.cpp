#include <bits/stdc++.h>
using namespace std;
long long int i, j, mod = 1e9 + 7;
long long int power(long long int x, long long int y, long long int mod) {
  x = x % mod;
  long long int res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res % mod;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int ncr(long long int n, long long int r, long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long int fact(long long int n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
long long int nCr(long long int n, long long int r) {
  if (r == 2)
    return (n * (n - 1)) / 2;
  else
    return (n * (n - 1) * (n - 2)) / 6;
}
bool isPos(vector<vector<long long int>> &arr1, long long int mid) {
  long long int m = arr1.size(), n = arr1[0].size();
  long long int total = 0, extra = 0;
  set<long long int> sel;
  for (i = 0; i < n; i++) {
    total = 0;
    for (j = 0; j < m; j++) {
      if (arr1[j][i] >= mid) {
        total = 1;
        if (sel.count(j)) extra = 1;
        sel.insert(j);
      }
    }
    if (!total) break;
  }
  return total && extra;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int t;
  cin >> t;
  while (t--) {
    long long int m, n;
    cin >> m >> n;
    vector<vector<long long int>> arr(m, vector<long long int>(n));
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) cin >> arr[i][j];
    }
    long long int strt = 1, end = 100000, ans = -1;
    while (strt <= end) {
      long long int mid = strt + (end - strt) / 2;
      if (isPos(arr, mid)) {
        ans = mid;
        strt = mid + 1;
      } else
        end = mid - 1;
    }
    cout << ans << endl;
  }
}
