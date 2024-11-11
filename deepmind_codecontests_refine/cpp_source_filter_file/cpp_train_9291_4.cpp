#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    char a[n][n];
    int i = 0, j = 0, t = 0, minr = INT_MAX, minc = INT_MAX, maxr = INT_MIN,
        maxc = INT_MIN;
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) a[i][j] = '0';
    if (t != k) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          t++;
          a[(i + j) % n][j] = '1';
          if (t == k) break;
        }
        if (t == k) break;
      }
    }
    int c = 0;
    for (i = 0; i < n; i++) {
      c = 0;
      for (j = 0; j < n; j++) {
        if (a[i][j] == 1) c++;
      }
      if (c < minr) minr = c;
      if (c > maxr) maxr = c;
    }
    for (i = 0; i < n; i++) {
      c = 0;
      for (j = 0; j < n; j++) {
        if (a[j][i] == 1) c++;
      }
      if (c < minc) minc = c;
      if (c > maxc) maxc = c;
    }
    cout << (maxr - minr) * (maxr - minr) + (maxc - minc) * (maxc - minc)
         << "\n";
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) cout << a[i][j];
      cout << "\n";
    }
  }
  return 0;
}
