#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, p, q, a[105][5], sum, t[101][101] = {0};
  cin >> n;
  sum = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= 4; j++) {
      cin >> a[i][j];
    }
    for (p = a[i][2]; p <= a[i][4]; p++) {
      for (q = a[i][1]; q <= a[i][3]; q++) {
        t[p][q]++;
      }
    }
  }
  for (i = 1; i <= 100; i++) {
    for (j = 1; j <= 100; j++) {
      sum += t[i][j];
    }
  }
  cout << sum;
  return 0;
}
