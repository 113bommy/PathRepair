#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int j, i, n, t, l, c, h, k, da, m, maxi, d, s, x;
  cin >> n;
  long long int minpo = -9999999999, minno = -999999999999;
  long long int a[n];
  s = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0) s = s + a[i];
    if (a[i] > 0 && a[i] > minpo && a[i] % 2 == 1) minpo = a[i];
    if (a[i] < 0 && a[i] > minno && abs(a[i]) % 2 == 1) minno = a[i];
  }
  if (s % 2 == 0) {
    if (minpo == -9999999999)
      s = s + minno;
    else if (minno = -999999999999)
      s = s - minpo;
    else
      s = s - min(minpo, -minno);
  }
  cout << s;
}
