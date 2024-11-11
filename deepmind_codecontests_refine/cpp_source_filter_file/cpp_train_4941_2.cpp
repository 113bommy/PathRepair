#include <bits/stdc++.h>
using namespace std;
int dcmp(double a, double b) {
  return fabs(a - b) <= 0.0000000001 ? 0 : (a > b) ? 1 : -1;
}
long long fun(long long lev) { return (3 * ((lev) * (lev + 1) / 2) - lev); }
int main() {
  long long n, i, s = 0, ans;
  cin >> n;
  for (i = 1;; i++) {
    ans = fun(i);
    if (ans > n) break;
    if ((ans + n) % 3 == 0) s++;
  }
  cout << s << endl;
}
