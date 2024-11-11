#include <bits/stdc++.h>
using namespace std;
const bool debug = false;
const int oo = 1000000000;
int n;
double a[2005];
int main() {
  if (!debug) {
    ios_base::sync_with_stdio(false);
  }
  cout << fixed << setprecision(3);
  cin >> n;
  for (int i = 1; i <= n * 2; i++) {
    cin >> a[i];
  }
  double sum = 0;
  int cntint = 0;
  for (int i = 1; i <= n * 2; i++) {
    if (a[i] > int(a[i])) {
      sum -= a[i] - int(a[i]);
    } else {
      cntint++;
    }
  }
  double ans = oo;
  if (cntint >= n) {
    ans = abs(sum);
  }
  int cntreal = 0;
  for (int i = 1; i <= n * 2; i++) {
    if (a[i] > int(a[i])) {
      cntreal++;
      sum += 1;
      if ((cntint + cntreal >= n) && (cntreal <= n)) {
        ans = min(ans, abs(sum));
      }
    }
  }
  if (debug) {
    cout << "n = " << n << "\na[] =";
    for (int i = 1; i <= n * 2; i++) {
      cout << " " << a[i];
    }
    cout << "\ncntint = " << cntint << ", cntreal = " << cntreal << "\n\n";
  }
  cout << ans << "\n";
  return 0;
}
