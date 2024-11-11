#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long b[3] = {0}, pd = 1, j = 0, ct;
    if (n == 5) {
      for (long long i = 1; i < n; i++) a[i] *= a[i - 1];
      cout << a[n - 1] << endl;
      continue;
    }
    for (long long i = 0; i < 4; i++) {
      if (a[i] >= 0) break;
      pd *= a[i];
      if (pd > 0) b[j++] = pd;
    }
    pd = 1, ct = 0;
    for (long long i = n - 1; i >= 0; i--) {
      pd *= a[i];
      ct++;
      if (ct == 1) b[1] *= pd;
      if (ct == 3) b[0] *= pd;
      if (ct == 5) b[2] = pd;
      if (ct == 5) break;
    }
    cout << max(b[0], max(b[1], b[2])) << endl;
  }
  return 0;
}
