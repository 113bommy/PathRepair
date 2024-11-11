#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, x[1007], i, j, p, q, r, s, t;
  double y[1007], tem;
  cin >> n >> r;
  d = r * 2;
  d = d * d;
  y[0] = r;
  for (i = 1; i <= n; i++) cin >> x[i];
  for (i = 1; i <= n; i++) {
    j = i - 1;
    tem = r;
    for (j = 1; j < i; j++) {
      p = abs(x[j] - x[i]);
      p = p * p;
      p = d - p;
      tem = max(tem, (double)sqrt(p) + y[j]);
    }
    y[i] = tem;
    cout << fixed << setprecision(10) << y[i] << " ";
  }
  cout << endl;
  return 0;
}
