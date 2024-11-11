#include <bits/stdc++.h>
int T, n, k, pos, res, mi;
int a[1000], b[500];
using namespace std;
int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> n >> k;
    res = 0;
    mi = 100000;
    for (int j = 1; j <= n; j++) {
      cin >> a[j];
      if (mi > a[j]) {
        mi = a[j];
        pos = j;
      }
    }
    for (int j = 1; j <= n; j++)
      if (pos != j) res += (k - a[j]) / mi;
    b[i] = res;
  }
  for (int i = 1; i <= T; i++) cout << b[i];
  return 0;
}
