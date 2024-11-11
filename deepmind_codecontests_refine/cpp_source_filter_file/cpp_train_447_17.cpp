#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n][n], r[n], c[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    r[i] = 0;
    for (int j = 0; j < n; j++) r[i] += a[i][j];
  }
  for (int i = 0; i < n; i++) {
    c[i] = 0;
    for (int j = 0; j < n; j++) c[i] += a[j][i];
  }
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (r[i] > c[j]) res++;
  cout << res;
}
