#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[100005], i, j, t, p, n, s1, s2;
  cin >> t;
  for (i = 0; i < t; i++) {
    s1 = 0;
    s2 = 0;
    p = 0;
    cin >> n;
    for (j = 0; j < n; j++) cin >> a[j];
    for (j = 0; j < n; j++) {
      s1 += a[j];
      if (s1 <= 0) {
        p = 1;
        break;
      }
    }
    for (j = n - 1; j >= 0; j--) {
      s2 += a[j];
      if (s2 <= 0) {
        p = 1;
        break;
      }
    }
    if (p == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
