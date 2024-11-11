#include <bits/stdc++.h>
int c[1000];
using namespace std;
int main() {
  int m, n;
  cin >> n >> m;
  int a[m][n], s[100], large = 0, x;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    large = a[i][0];
    s[i] = 1;
    for (int j = 0; j < n; j++) {
      if (a[i][j] > large) {
        large = a[i][j];
        s[i] = j + 1;
      }
    }
    x = s[i];
    c[x]++;
  }
  int l = 0, s1 = 1;
  for (int i = 1; i <= 100; i++) {
    if (c[i] > l) {
      l = c[i];
      s1 = i;
    }
  }
  cout << s1;
}
