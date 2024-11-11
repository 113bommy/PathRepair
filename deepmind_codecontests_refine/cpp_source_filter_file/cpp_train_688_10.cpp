#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, a[1000];
  char b[1000];
  cin >> n;
  if (n == 1) a[0] = 1;
  if (n >= 2) {
    a[0] = 1;
    a[1] = 1;
  }
  for (j = 0; j <= 15; j++) b[j] = 'o';
  for (i = 2; i <= 15; i++) {
    a[i] = a[i - 2] + a[i - 1];
  }
  for (j = 1; j <= 15; j++) {
    b[a[j]] = 'O';
  }
  for (j = 1; j <= n; j++) cout << b[j];
  return 0;
}
