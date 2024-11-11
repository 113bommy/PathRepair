#include <bits/stdc++.h>
using namespace std;
int m, n, k, i, j, x, y, a[10001], b;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    a[k]++;
  }
  for (i = 0; i < n; i++) b += a[i] / 2;
  cout << b / 2;
  return 0;
}
