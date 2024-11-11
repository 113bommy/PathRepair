#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  cin >> n >> m;
  int c[m], a[n];
  int i, j, k;
  for (i = 0; i < n; i++) {
    a[i] = 0;
  }
  for (i = 0; i < m; i++) {
    cin >> c[i];
    a[c[i] + 1]++;
  }
  k = a[0];
  for (i = 0; i < n; i++) {
    if (k < a[i]) {
      k = a[i];
    }
  }
  cout << k;
  return 0;
}
