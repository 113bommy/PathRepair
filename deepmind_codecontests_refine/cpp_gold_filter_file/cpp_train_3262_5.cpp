#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, i;
  cin >> n >> b;
  double a[n];
  double z, k, sum = 0, c[n], x, max = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= max) max = a[i];
  }
  for (i = 0; i < n; i++) {
    c[i] = max - a[i];
    sum = sum + c[i];
  }
  z = (double)b - sum;
  k = (double)n;
  if (z < 0) {
    cout << "-1\n";
    exit(0);
  } else {
    x = z / k;
  }
  for (i = 0; i < n; i++) {
    cout << setprecision(9) << c[i] + x << endl;
  }
}
