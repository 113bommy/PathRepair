#include <bits/stdc++.h>
using namespace std;
long a[1001], b[3];
int main() {
  long n, i, dem, t;
  cin >> n;
  t = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    t = t + a[i];
  }
  if (t % n != 0)
    cout << "Unrecoverable configuration.";
  else {
    dem = 0;
    for (i = 1; i <= n; i++)
      if (a[i] != t / n) {
        dem++;
        if (dem > 2) {
          break;
        } else
          b[dem] = i;
      }
    if (dem == 0) {
      cout << "Exemplary pages.";
    } else if (dem == 2) {
      if ((a[b[1]] + a[b[2]]) / 2 == t / n)
        if (a[b[1]] > a[b[2]])
          cout << a[b[1]] - t / n << " ml. from cup #" << b[2] << " to cup #"
               << b[1] << ".";
        else
          cout << a[b[2]] - t / n << " ml. from cup #" << b[1] << " to cup #"
               << b[2] << ".";
      else
        cout << "Unrecoverable configuration.";
    } else
      cout << "Unrecoverable configuration.";
  }
}
