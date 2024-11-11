#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, i, j, k, len, z, c, f, flag, q, mx, mn, l, r, sum, ans, tmp,
      it, pos, avg, m, cnt;
  {
    unsigned long long int a, b;
    f = 0;
    flag = 0;
    ans = 0;
    cnt = 0;
    sum = 0;
    mn = LLONG_MAX;
    mx = LLONG_MIN;
    string s;
    cin >> a >> b;
    unsigned long long int X = b;
    unsigned long long int A = (a - b) / 2;
    if (a < b || (b & 1) != (a & 1) || A < 0 || (a & b)) {
      cout << 0;
      return 0;
    }
    unsigned long long int p, x, y;
    x = y = 0;
    ans = 1;
    for (i = 64 - 1; i >= 0; i--) {
      p = 1;
      p = p << i;
      l = X & p;
      r = A & p;
      if (!l && r) x |= p, y |= p;
      if (l && !r) ans *= 2, x |= p;
    }
    if (0 == A) ans -= 2;
    cout << ans << "\n";
  }
  return 0;
}
