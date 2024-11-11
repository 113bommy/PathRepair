#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r = 0;
  cin >> n;
  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < (n - 2); i++) {
    if ((a[i] == a[i + 1]) && (a[i + 1] == a[i + 2])) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < (n - 1); i++) {
    if (a[i] == a[i + 1]) {
      b[r] = a[i];
      r++;
      a[i] = -1;
    }
  }
  cout << r << '\n';
  for (int i = 0; i < r; i++) cout << b[i] << ' ';
  cout << '\n' << (n - r) << '\n';
  for (int i = (n - 1); i >= 0; i--) {
    if (a[i] > 0) cout << a[i] << ' ';
  }
  return 0;
}
