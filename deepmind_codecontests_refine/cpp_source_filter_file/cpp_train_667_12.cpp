#include <bits/stdc++.h>
using namespace std;
bool fun(int a[], int b[], int n, int v, double x) {
  double t = 0.0;
  int i;
  for (i = 0; i < n; i++) {
    if (a[i] * x <= b[i])
      t += a[i] * x;
    else
      return false;
    if (t > v) return false;
  }
  return true;
}
int main() {
  int n, v, i, j, k;
  cin >> n >> v;
  int a[n], b[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  double low = 0.0, high = 100.0, mid;
  while ((high - low) >= 0.00001) {
    mid = (high + low) / 2;
    if (fun(a, b, n, v, mid))
      low = mid;
    else
      high = mid;
  }
  double t = 0.0;
  for (i = 0; i < n; i++) t += a[i] * low;
  cout << t;
}
