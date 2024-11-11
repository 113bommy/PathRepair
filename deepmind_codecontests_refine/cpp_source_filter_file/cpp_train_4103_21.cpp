#include <bits/stdc++.h>
using namespace std;
int panduan(int a[], int b[], int n, int m, int k) {
  int i, j;
  int p = 0;
  int temp;
  for (i = 1; i < m + 1; i++) {
    temp = 1100000;
    for (j = 0; j < n - 1; j++) {
      if (a[j] == i) {
        if (b[j] <= temp) {
          temp = b[j];
        }
      }
    }
    p = p + temp;
  }
  if (p <= k) return p;
  return k;
}
int main() {
  int a[1010], b[1010];
  int i, n, m, k;
  cin >> n >> m >> k;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (i = 0; i < n; i++) cin >> a[i] >> b[i];
  cout << panduan(a, b, n, m, k) << endl;
  return 0;
}
