#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, m, i, j, x = 0, y = 1;
  cin >> n;
  long long int a[n + 5], b[n + 5], c[n + 5];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  memset(c, 0, sizeof(c));
  sort(b, b + n);
  reverse(b, b + n);
  for (i = 0; i < n; i++) {
    if (b[i] == b[i + 1]) {
      b[i] = -1;
    }
  }
  for (i = 0; i < n; i++) {
    y = y + x;
    x = 0;
    for (j = 0; j < n; j++) {
      if (b[i] == a[j]) {
        c[j] = y;
        x++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    cout << c[i] << " ";
  }
}
