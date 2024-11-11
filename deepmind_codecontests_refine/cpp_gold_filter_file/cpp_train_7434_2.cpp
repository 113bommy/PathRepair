#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d, m;
  cin >> n >> d;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  sort(a, a + n);
  int suma = 0;
  if (m > n) {
    for (int i = 0; i < n; i++) {
      suma += a[i];
      m--;
    }
    cout << suma - m * d;
  } else {
    for (int i = 0; i < m; i++) {
      suma += a[i];
    }
    cout << suma;
  }
  return 0;
}
