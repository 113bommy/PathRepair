#include <bits/stdc++.h>
using namespace std;
int isprime(int n) {
  if (n == 1) return 0;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  int n, m;
  cin >> n >> m;
  int i;
  for (i = n; i <= 2 * n; i++) {
    if (isprime(i)) break;
  }
  cout << 2 << " " << i << endl;
  for (int j = 1; j <= n - 2; j++) {
    cout << j << " " << j + 1 << " " << 1 << endl;
  }
  cout << n - 1 << " " << n << " " << i - (n - 2) << endl;
  m -= (n - 1);
  while (m > 0) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 2; j <= n; j++) {
        cout << i << " " << j << " " << 1000000000 << endl;
        m -= 1;
        if (m == 0) break;
      }
      if (m == 0) break;
    }
  }
}
