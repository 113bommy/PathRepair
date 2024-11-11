#include <bits/stdc++.h>
using namespace std;
int n, a[2][60], b[60], c[60];
int main() {
  cin >> n;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n - 1; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    c[i] = b[i];
    for (int j = 0; j < i; j++) {
      c[i] += a[0][j];
    }
    for (int j = i; j < n - 1; j++) {
      c[i] += a[1][j];
    }
  }
  sort(c, c + n);
  cout << c[0] + c[1] << endl;
  return 0;
}
