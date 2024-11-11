#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  long long i, j, k, n, m, t, f1, f2, temp;
  while (!cin.eof() && cin >> n >> m) {
    cin >> f1;
    for (i = 1; i <= n; i++) cin >> temp;
    cin >> f2;
    for (i = 1; i <= m; i++) cin >> temp;
    if (n > m) {
      if (f1 > 0 && f2 < 0 || f1 < 0 && f2 > 0)
        cout << "-Infinity" << endl;
      else
        cout << "Infinity" << endl;
    } else if (n < m)
      cout << "0/1" << endl;
    else if (n == m) {
      if (f1 < 0 && f2 > 0 || f1 > 0 && f2 < 0) cout << "-";
      f1 = abs(f1);
      f2 = abs(f2);
      cout << f1 / gcd(f1, f2) << "/" << f2 / gcd(f1, f2) << endl;
    }
  }
  return 0;
}
