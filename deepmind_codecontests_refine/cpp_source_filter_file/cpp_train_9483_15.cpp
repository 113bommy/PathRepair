#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, games;
  cin >> n >> m;
  int c[n];
  int a[m];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < m; i++) cin >> a[i];
  i = 0;
  j = 0;
  games = 0;
  while (i < n) {
    if (c[i] <= a[j]) {
      games++;
      i++;
      j++;
    } else
      i++;
  }
  cout << games;
}
