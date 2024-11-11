#include <bits/stdc++.h>
using namespace std;
long long int x[1000007], y[1000007], z[1000007], n;
string s, S;
int main() {
  {
    long long int c = 0, d, diff, e, f, g, i, j, k, l, m, in, h, mod, loc, p, q,
                  r, u, val, w, t, tc, sz, lo, hi, mid, mn = 2134567891, mx = 0,
                  sum = 0, ans = 0;
    cin >> n >> m >> h;
    h--;
    for (i = 0; i < m; i++) cin >> x[i], sum += x[i];
    if (sum < n)
      cout << "-1\n";
    else if (x[h] == 1)
      cout << "0\n";
    else if (sum == n)
      cout << "1\n";
    else {
      double a, b, aa = 1.0;
      a = sum - x[h] + 1;
      b = sum;
      for (i = 1; i <= n - 1; i++) {
        aa *= (a - i) / (b - i);
      }
      cout << setprecision(10) << fixed;
      cout << 1 - aa << endl;
    }
  }
  return 0;
}
