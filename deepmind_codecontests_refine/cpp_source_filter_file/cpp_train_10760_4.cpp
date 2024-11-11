#include <bits/stdc++.h>
using namespace std;
int a[33][33];
int k[33];
bool met[33 * 33];
int x;
int n, kk, l, i, j;
int main() {
  cin >> n >> kk;
  for (i = 0; i < n; i++) {
    cin >> x;
    a[i][k[i]++] = x;
    met[x] = true;
  }
  l = 1;
  for (i = 0; i < n; i++) {
    while (k[i] < kk) {
      while (met[l]) l++;
      a[i][k[i]++] = l;
      met[l] = true;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < kk; j++) cout << a[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
