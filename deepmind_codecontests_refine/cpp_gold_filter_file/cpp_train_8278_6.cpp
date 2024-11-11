#include <bits/stdc++.h>
using namespace std;
unsigned long long int sum(unsigned long long int s, unsigned long long int n,
                           unsigned long long int a[],
                           unsigned long long int b[],
                           unsigned long long int k) {
  unsigned long long int i, m = 0;
  for (i = 0; i < n; i++) {
    if ((s * a[i]) > b[i]) {
      m = m + (a[i] * s - b[i]);
    }
  }
  if (m > k) return (0);
  return (1);
}
int main() {
  unsigned long long int i, j, n, m, f, l, x, k, min, max = 0, s = 0, total = 0;
  cin >> n >> k;
  unsigned long long int a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  f = 0;
  l = 200000000000;
  while (l - f > 1) {
    m = f + (l - f) / 2;
    if (sum(m, n, a, b, k)) {
      total = m;
      f = m;
    } else {
      l = m;
    }
  }
  cout << total;
  return (0);
}
