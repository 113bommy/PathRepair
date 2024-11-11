#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, n, m, t, k, ans, f, l, r, x, y, p, q;
  cin >> t;
  while (t--) {
    cin >> n;
    string se;
    cin >> se;
    p = 0;
    q = 0;
    for (i = 0; i < n; i++) {
      if (se[i] == '(')
        p++;
      else {
        if (x == 0)
          q++;
        else
          p--;
      }
    }
    cout << (p + q) / 2 << "\n";
  }
  return 0;
}
