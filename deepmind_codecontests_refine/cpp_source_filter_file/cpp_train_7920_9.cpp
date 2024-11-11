#include <bits/stdc++.h>
using namespace std;
long long int n, m, a[1000005];
int main() {
  cin >> m >> n;
  for (long long int i = 0; i < n; i++) {
    cout << m << '\n';
    fflush(stdout);
    long long int k;
    cin >> k;
    if (k == 0) return 0;
    if (k == -1)
      a[i] = 1;
    else
      a[i] = 0;
  }
  long long int lo = 0;
  long long int hi = m;
  long long int pro = 0;
  while (lo <= hi) {
    long long int mid = (lo + hi) / 2;
    cout << mid << '\n';
    fflush(stdout);
    long long int k;
    cin >> k;
    if (k == 0) return 0;
    if (a[pro]) {
      if (k == -1)
        hi = mid - 1;
      else
        lo = mid + 1;
    } else {
      if (k == -1)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    pro++;
    pro %= n;
  }
  return 0;
}
