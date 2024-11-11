#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int result = power(a, n / 2);
  result = result * result;
  if (n % 2) result *= a;
  return result;
}
int main() {
  long long int i, j, l, t, m, n, k;
  long long int ans = 0;
  cin >> n >> m;
  int v[m][2];
  if (m == 0) {
    cout << n - 2 << endl;
    return 0;
  }
  for (i = 0; i < m; i++) {
    cin >> v[i][0] >> v[i][1];
  }
  int a[n];
  memset(a, 0, sizeof(a));
  for (i = 0; i < m; i++) {
    j = v[i][0] - 1;
    k = v[i][1] - 1;
    if (j > k) {
      t = j;
      j = k;
      k = t;
    }
    if (a[k] == 1 || a[j] == 2) {
      cout << 0 << endl;
      return 0;
    }
    a[k] = 2;
    a[j] = 1;
  }
  k = 0, j = 0;
  for (i = 0; i < n; i++) {
    if (a[i] == 1) k = i;
  }
  for (i = n - 1; i >= 0; i--) {
    if (a[i] == 2) j = i;
  }
  if (k >= j) {
    cout << 0 << endl;
    return 0;
  }
  ans = j - k;
  cout << ans << endl;
  return 0;
}
