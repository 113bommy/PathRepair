#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
  int n, c;
  cin >> n >> c;
  double k = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (i + c - 1 >= n) {
      continue;
    }
    double kol = 0, kol1 = 0;
    for (int j = i; j < n; j++) {
      kol++;
      kol1 += a[j];
      if (kol >= c) {
        k = max(k, kol1 / kol);
      }
    }
  }
  cout << setprecision(11) << k;
}
