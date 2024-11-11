#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n - 1], c[n - 2];
  for (int i = 0; i < n; ++i) cin >> a[i];
  b[n - 1] = 1e9;
  c[n - 2] = 1e9;
  for (int i = 0; i < n - 1; ++i) cin >> b[i];
  for (int i = 0; i < n - 2; ++i) cin >> c[i];
  sort(a, a + n);
  sort(b, b + n - 1);
  sort(c, c + n - 2);
  for (int i = 0;; ++i)
    if (a[i] != b[i]) {
      cout << a[i] << " ";
      break;
    } else
      cerr << "P";
  for (int i = 0;; ++i)
    if (b[i] != c[i]) {
      cout << b[i];
      break;
    } else
      cerr << "O";
  return 0;
}
