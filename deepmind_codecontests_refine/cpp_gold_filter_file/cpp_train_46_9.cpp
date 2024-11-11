#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n - 1], c[n - 2], p, q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  sort(b, b + (n - 1));
  for (int i = 0; i < n - 2; i++) {
    cin >> c[i];
  }
  sort(c, c + (n - 2));
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != b[i]) {
      p = a[i];
      break;
    }
    if (i == n - 2) {
      p = a[n - 1];
    }
  }
  for (int i = 0; i < n - 2; i++) {
    if (c[i] != b[i]) {
      q = b[i];
      break;
    }
    if (i == n - 3) {
      q = b[n - 2];
    }
  }
  cout << p << '\n' << q;
  return 0;
}
