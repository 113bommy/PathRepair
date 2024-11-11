#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100][100];
void sortMat() {
  long long temp[n * m];
  long long k = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) temp[k++] = a[i][j];
  sort(temp, temp + k);
  k = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) a[i][j] = temp[k++];
}
void oka() {
  long long t, j, i, mid, f = 0, mn = 1000000000000010010, sum = 0, p, k, mid1,
                          cnt = 0;
  cin >> n >> m >> t;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  if (t != 1) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if ((abs(a[i][j] - a[i][j + 1]) % t != 0 && j + 1 < m) ||
            (abs(a[i + 1][j] - a[i][j]) % t != 0 && i + 1 < n)) {
          cout << -1 << endl;
          return;
        }
      }
    }
  }
  sortMat();
  mid = (n * m / 2) + 1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cnt++;
      if (cnt == mid) {
        mid1 = a[i][j];
        break;
      }
    }
  }
  for (k = 0; k < n; k++) {
    for (p = 0; p < m; p++) {
      sum += (abs((a[k][p] - mid1)) / t);
    }
  }
  cout << sum << endl;
}
int main() { oka(); }
