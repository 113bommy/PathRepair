#include <bits/stdc++.h>
using namespace std;
long long a[500][500];
int main() {
  long long n, x1, y1, x2, y2, sum = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (long long j = min(x1, x2); j <= max(x1, x2); j++) {
      for (long long k = min(y1, y2); k <= max(y1, y2); k++) {
        a[j - 1][k - 1]++;
      }
    }
  }
  for (long long i = 0; i < 100; i++) {
    for (long long j = 0; j < 100; j++) {
      sum += a[i][j];
    }
  }
  cout << sum;
  return 0;
}
