#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i;
  cin >> n;
  long long a[n], b[n - 1], c[n - 2];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n - 1);
  for (i = 0; i < n - 1;) {
    if (a[i] != b[i]) {
      cout << a[i] << endl;
      break;
    }
    i++;
  }
  if (i == n - 1) {
    cout << a[n - 1] << endl;
  }
  for (i = 0; i < n - 2; i++) {
    cin >> c[i];
  }
  sort(c, c + n - 2);
  for (i = 0; i < n - 2;) {
    if (b[i] != c[i]) {
      cout << b[i] << endl;
      break;
    }
    i++;
  }
  if (i == n - 2) {
    cout << b[n - 2] << endl;
  }
  return 0;
}
