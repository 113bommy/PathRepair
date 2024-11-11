#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i, j;
  cin >> n;
  long long int a[n], b[n - 1], c[n - 2];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  for (j = 0; j < n - 2; j++) {
    cin >> c[j];
  }
  sort(a, a + n);
  sort(b, b + n - 1);
  sort(c, c + n - 2);
  for (i = 0; i < n - 1; i++) {
    if (a[i] != b[i]) {
      cout << a[i] << endl;
      goto x;
    }
  }
  cout << a[n - 1];
x:;
  for (i = 0; i < n - 2; i++) {
    if (c[i] != b[i]) {
      cout << b[i] << endl;
      goto y;
    }
  }
  cout << b[n - 2] << endl;
  ;
y:;
}
