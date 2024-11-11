#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a[111111], b[111111], c[111111];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n - 2; i++) {
    cin >> c[i];
  }
  sort(a, a + n);
  sort(b, b + n - 1);
  sort(c, c + n - 2);
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cout << a[i];
      break;
    }
  }
  cout << '\n';
  for (int i = 0; i < n - 1; i++) {
    if (b[i] != c[i]) {
      cout << b[i];
      break;
    }
  }
  return 0;
}
