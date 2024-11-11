#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int b[n];
  for (int i = 0; i < n; ++i) cin >> b[i];
  sort(b, b + n);
  int k1, k2;
  k1 = b[n - 1] + m;
  for (int i = 0; i < n; ++i) {
    if (b[n - 1] - b[i] < m) {
      m = m - b[n - 1] + b[i];
    } else {
      m = 0;
    }
  }
  if (m % n != 0)
    k2 = b[n - 1] + m / n + 1;
  else
    k2 = b[n - 1] + m / n;
  cout << k2 << " " << k1;
}
