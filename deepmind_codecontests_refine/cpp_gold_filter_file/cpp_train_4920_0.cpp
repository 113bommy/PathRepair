#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
long long a[maxn], ind[maxn];
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i], ind[a[i]] = i;
    long long MAX, MIN, num1, num2;
    for (long long i = 0; i < n; i++) {
      if (a[i] == 1) MIN = i, num1 = a[i];
      if (a[i] == n) MAX = i, num2 = a[i];
    }
    if (MAX == n - 1 || MIN == 0)
      cout << "YES" << '\n';
    else if (MAX == 0 || MIN == n - 1)
      cout << "NO" << '\n';
    else {
      bool ispos = 0;
      num1++;
      num2--;
      for (long long i = 0; i < n; i++) {
        if (ind[num1] == 0) {
          ispos = 1;
          break;
        } else
          num1++;
        if (ind[num2] == n - 1) {
          ispos = 1;
          break;
        } else
          num2--;
        if (ind[num1 - 1] == n - 1 || ind[num2 + 1] == 0) break;
      }
      if (ispos)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
