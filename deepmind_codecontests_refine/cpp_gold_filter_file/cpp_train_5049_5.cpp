#include <bits/stdc++.h>
using namespace std;
unsigned long long a[200203];
unsigned long long b[203420];
unsigned long long c[203433];
int main() {
  unsigned long long n, m, x;
  cin >> n >> m >> x;
  unsigned long long i, j, k;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= n; i++) {
    b[i] = b[i - 1] | a[i];
  }
  for (j = n; j >= 1; j--) {
    c[j] = c[j + 1] | a[j];
  }
  unsigned long long tmp;
  unsigned long long mx = 0;
  int z = 1;
  for (i = 0; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      tmp = b[j - 1] | (a[j] * z) | c[j + 1];
      mx = max(mx, tmp);
    }
    z *= x;
  }
  cout << mx << endl;
  return 0;
}
