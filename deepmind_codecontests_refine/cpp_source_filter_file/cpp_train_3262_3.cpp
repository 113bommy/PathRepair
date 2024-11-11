#include <bits/stdc++.h>
using namespace std;
int main() {
  double a[110], b, sum;
  int i, n;
  cin >> n >> b;
  sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum += b;
  sum /= double(n);
  bool f = 0;
  for (i = 0; i < n; i++) {
    if (a[i] < sum)
      a[i] = sum - a[i];
    else {
      f = 1;
      break;
    }
  }
  if (f)
    cout << -1 << endl;
  else {
    for (i = 0; i < n; i++) printf("%.6lf\n", a[i]);
  }
}
