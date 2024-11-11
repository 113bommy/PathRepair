#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return (a > b); }
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main(void) {
  string s;
  cin >> s;
  int n, l, r, i;
  int x[100001] = {0}, y[100001] = {0}, z[100001] = {0}, d[3];
  for (i = 1; i <= s.size(); ++i) {
    if (s[i - 1] == 'x')
      x[i] = x[i - 1] + 1;
    else
      x[i] = x[i - 1];
    if (s[i - 1] == 'y')
      y[i] = y[i - 1] + 1;
    else
      y[i] = y[i - 1];
    if (s[i - 1] == 'z')
      z[i] = z[i - 1] + 1;
    else
      z[i] = z[i - 1];
  }
  cin >> n;
  while (n--) {
    cin >> l >> r;
    if (r - l < 3)
      cout << "YES\n";
    else {
      d[0] = x[r] - x[l - 1];
      d[1] = y[r] - y[l - 1];
      d[2] = z[r] - z[l - 1];
      sort(d, d + 3);
      if (d[2] - d[0] > 1)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
