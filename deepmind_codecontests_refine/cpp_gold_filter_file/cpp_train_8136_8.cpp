#include <bits/stdc++.h>
using namespace std;
long long int a[100001], b[100001];
long long int kk[100001][10];
long long int val(long long int n, long long int k) {
  if (n == 0) return kk[n][k] = 0;
  if (k == 0) {
    if (kk[n][k] == -1)
      return kk[n][k] =
                 max(max(b[n - 1] + val(n - 1, 2), a[n - 1] + val(n - 1, 1)),
                     val(n - 1, 0));
    else
      return kk[n][k];
  }
  if (k == 1) {
    if (kk[n][k] == -1)
      return kk[n][k] = max(b[n - 1] + val(n - 1, 2), val(n - 1, 0));
    else
      return kk[n][k];
  }
  if (k == 2) {
    if (kk[n][k] == -1)
      return kk[n][k] = max(a[n - 1] + val(n - 1, 1), val(n - 1, 0));
    else
      return kk[n][k];
  }
}
int main() {
  int t;
  t = 1;
  while (t--) {
    long long int i, j, k, n;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (j = 0; j < n; j++) {
      cin >> b[j];
    }
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= 2; j++) {
        kk[i][j] = -1;
      }
    }
    cout << val(n, 0);
  }
}
