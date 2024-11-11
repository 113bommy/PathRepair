#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, t, a[200], sub = 0, flag = 0, ctr = 0;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sub = 86400 - a[i];
    if ((sub - t) >= 0 && ctr == 0) {
      flag++;
      ctr++;
    } else if (ctr == 0)
      flag++;
    t = t - sub;
  }
  cout << flag;
  return 0;
}
