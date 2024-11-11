#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int a[m][n], i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  long long int b[m], c[n];
  memset(c, 0, sizeof(c));
  for (i = 0; i < m; i++) {
    long long int l = INT_MIN;
    for (j = 0; j < n; j++) {
      if (a[i][j] > l) {
        l = a[i][j];
        b[i] = j;
      }
    }
  }
  for (j = 0; j < m; j++) {
    c[b[j]]++;
  }
  long long int l = INT_MIN;
  for (j = 0; j < n; j++) {
    if (c[j] > l) {
      l = c[j];
      k = j;
    }
  }
  cout << k + 1 << endl;
  return 0;
}
