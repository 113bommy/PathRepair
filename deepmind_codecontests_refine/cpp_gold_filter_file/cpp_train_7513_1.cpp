#include <bits/stdc++.h>
using namespace std;
mt19937 roi(chrono::high_resolution_clock::now().time_since_epoch().count());
int p[2] = {(int)1e9 + 7, (int)1e9 + 9 + 228};
signed main() {
  long long n, m;
  cin >> n >> m;
  bool f[n][m], reach[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '.')
        f[i][j] = true;
      else
        f[i][j] = false;
    }
  }
  reach[0][0] = true;
  for (long long i = 1; i < n; i++) {
    reach[i][0] = reach[i - 1][0];
    if (!f[i][0]) reach[i][0] = false;
  }
  for (long long j = 1; j < m; j++) {
    reach[0][j] = reach[0][j - 1];
    if (!f[0][j]) reach[0][j] = false;
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < m; j++) {
      reach[i][j] = reach[i - 1][j] || reach[i][j - 1];
      if (!f[i][j]) reach[i][j] = false;
    }
  }
  if (!reach[n - 1][m - 1]) {
    cout << "0";
    return 0;
  }
  long long ans = 0;
  long long a[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      a[i][j] = 0;
    }
  }
  for (long long itp = 0; itp < 2; itp++) {
    long long pr = p[itp];
    long long k1[n][m];
    k1[0][0] = 1;
    for (long long i = 1; i < n; i++) {
      k1[i][0] = k1[i - 1][0];
      if (!f[i][0]) k1[i][0] = 0;
    }
    for (long long i = 1; i < m; i++) {
      k1[0][i] = k1[0][i - 1];
      if (!f[0][i]) k1[0][i] = 0;
    }
    for (long long i = 1; i < n; i++) {
      for (long long j = 1; j < m; j++) {
        k1[i][j] = k1[i - 1][j] + k1[i][j - 1];
        if (!f[i][j]) k1[i][j] = 0;
        k1[i][j] %= pr;
      }
    }
    long long k2[n][m];
    k2[n - 1][m - 1] = 1;
    for (long long i = n - 2; i >= 0; i--) {
      k2[i][m - 1] = k2[i + 1][m - 1];
      if (!f[i][m - 1]) k2[i][m - 1] = 0;
    }
    for (long long i = m - 2; i >= 0; i--) {
      k2[n - 1][i] = k2[n - 1][i + 1];
      if (!f[n - 1][i]) k2[n - 1][i] = 0;
    }
    for (long long i = n - 2; i >= 0; i--) {
      for (long long j = m - 2; j >= 0; j--) {
        k2[i][j] = k2[i + 1][j] + k2[i][j + 1];
        if (!f[i][j]) k2[i][j] = 0;
        k2[i][j] %= pr;
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (k1[i][j] * k2[i][j] % pr == k2[0][0]) {
          a[i][j]++;
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == 2 && !((i == 0 && j == 0) || (i == n - 1 && j == m - 1))) {
        cout << "1";
        return 0;
      }
    }
  }
  cout << "2";
  return 0;
}
