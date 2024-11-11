#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long po = 0;
  if ((n * n) % 2 == 0)
    po = (n * n) / 2;
  else
    po = ((n * n) / 2) + 1;
  if (po < k)
    cout << "NO";
  else {
    cout << "YES" << endl;
    char c[n][n];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) c[i][j] = 'S';
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (k > 0 and (i + j) % 2 == 0) {
          c[i][j] = 'L';
          k--;
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      {
        for (long long j = 0; j < n; j++) cout << c[i][j];
      }
      cout << endl;
    }
  }
}
