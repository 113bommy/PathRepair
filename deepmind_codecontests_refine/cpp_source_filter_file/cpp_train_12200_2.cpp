#include <bits/stdc++.h>
using namespace std;
long long mysqrt(long long x) {
  long long l = 0;
  long long r = 1;
  while (r * r <= x) r *= 2;
  while (r - l > 1) {
    long m = (l + r) / 2;
    if (m * m <= x)
      l = m;
    else
      r = m;
  }
  return l;
}
int main() {
  long long n;
  cin >> n;
  long long a[n + 2][n + 2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    int k = (j + 1) % n;
    cout << mysqrt(1ll * a[i][j] * a[i][k] / a[j][k]) << "\n";
  }
}
