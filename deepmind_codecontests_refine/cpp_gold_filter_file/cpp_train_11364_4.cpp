#include <bits/stdc++.h>
using namespace std;
long long int MX = 1e18 + 100;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, c, i, j, k, q, p, x, y, sum, ct, ct1, m, l, r, x1, y1, mn,
      n, mx, ans, h, sum1, len, in;
  char ch;
  double d;
  string str1, str2, str;
  bool bl, bl1;
  int cs = 1, t;
  while (cin >> n) {
    long long int ara[n + 2];
    for (i = 1; i <= n; i++) {
      cin >> ara[i];
    }
    mn = MX;
    for (i = 1; i <= n; i++) {
      if (i != 1) mn = min(mn, (min(ara[i], ara[1]) / (i - 1)));
      if (i != n) mn = min(mn, ((min(ara[n], ara[i])) / (n - i)));
    }
    cout << mn << endl;
  }
}
