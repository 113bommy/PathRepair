#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 + 5;
int r[maxN], c[maxN];
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1) r[0] = 1;
  if (n == 2) r[0] = 3, r[1] = 4;
  if (n > 2) {
    if (n & 1) {
      r[0] = 2;
      for (int i = 1; i < n - 1; i++) r[i] = 1;
      r[n - 1] = (n + 1) / 2;
    } else {
      for (int i = 0; i < n - 1; i++) r[i] = 1;
      r[n - 1] = (n - 2) / 2;
    }
  }
  if (m == 1) c[0] = 1;
  if (m == 2) c[0] = 3, c[1] = 4;
  if (m > 2) {
    if (m & 1) {
      c[0] = 2;
      for (int i = 1; i < m - 1; i++) c[i] = 1;
      c[m - 1] = (m + 1) / 2;
    } else {
      for (int i = 0; i < m - 1; i++) c[i] = 1;
      c[m - 1] = (m - 2) / 2;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << r[i] * c[j] << ' ';
    cout << endl;
  }
}
