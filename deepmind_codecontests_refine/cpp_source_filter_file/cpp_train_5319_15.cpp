#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, c = 0;
  double m;
  cin >> n >> m;
  double a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) c = 1;
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
    if (a[i] == 1) c = 1;
  }
  if (c == 1)
    cout << "-1" << endl;
  else {
    double x = m / (b[0] - 1);
    for (i = n - 1; i > 0; i--) {
      x = (a[i] * x + m) / (a[i] - 1);
      x = (b[i] * x + m) / (b[i] - 1);
    }
    x = (a[0] * x + m) / (a[0] - 1);
    cout << setprecision(8) << x << endl;
  }
}
