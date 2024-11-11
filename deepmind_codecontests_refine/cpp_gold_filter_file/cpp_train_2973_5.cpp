#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s, e;
  cin >> n >> s >> e;
  s--;
  e--;
  long long x[n];
  long long a[n];
  long long b[n];
  long long c[n];
  long long d[n];
  for (long long i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> d[i];
  }
  long long** tabel = new long long*[n];
  for (long long i = 0; i < n; i++) {
    tabel[i] = new long long[n];
    for (long long j = 0; j < n; j++) {
      tabel[i][j] = 10000000000000;
    }
  }
  if (s != 0 && e != 0) {
    tabel[0][0] = b[0] + d[0];
  }
  if (s == 0) {
    tabel[0][0] = d[0];
  }
  if (e == 0) {
    tabel[0][0] = b[0];
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < i; j++) {
      tabel[i - 1][j] += ((j + 1) * 2 * (x[i] - x[i - 1]));
      if (s < i) {
        tabel[i - 1][j] -= (x[i] - x[i - 1]);
      }
      if (e < i) {
        tabel[i - 1][j] -= (x[i] - x[i - 1]);
      }
      if (s == i) {
        tabel[i][j + 1] = min(tabel[i][j + 1], tabel[i - 1][j] + d[i]);
        if (e > i || j > 0 || i == n - 1) {
          tabel[i][j] = min(tabel[i][j], tabel[i - 1][j] + c[i]);
        }
        continue;
      }
      if (e == i) {
        tabel[i][j + 1] = min(tabel[i][j + 1], tabel[i - 1][j] + b[i]);
        if (s > i || j > 0 || i == n - 1) {
          tabel[i][j] = min(tabel[i][j], tabel[i - 1][j] + a[i]);
        }
        continue;
      }
      tabel[i][j + 1] = min(tabel[i][j + 1], tabel[i - 1][j] + d[i] + b[i]);
      if (s > i || j > 0) {
        tabel[i][j] = min(tabel[i][j], tabel[i - 1][j] + c[i] + b[i]);
      }
      if (e > i || j > 0) {
        tabel[i][j] = min(tabel[i][j], tabel[i - 1][j] + a[i] + d[i]);
      }
      if (j > 0 && (s > i || e > i || j > 1 || i == n - 1)) {
        tabel[i][j - 1] = min(tabel[i][j - 1], tabel[i - 1][j] + a[i] + c[i]);
      }
    }
  }
  cout << tabel[n - 1][0] << endl;
  cin >> n;
}
