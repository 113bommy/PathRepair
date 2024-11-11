#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int mn = 100000000000000, m = 0, p = 0, f, s = 0, z = 0;
  for (long long int i = 0; i < n + n - 1; i++) {
    cin >> f;
    long long int g = f;
    if (g < 0) g *= -1;
    mn = min(mn, g);
    s += g;
    if (f < 0)
      m++;
    else if (f == 0)
      z++;
    else
      p++;
  }
  if (n % 2 == 0) {
    if (m % 2 == 0 || z > 0)
      cout << s << endl;
    else
      cout << s - mn << endl;
  } else
    cout << s << endl;
}
