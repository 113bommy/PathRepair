#include <bits/stdc++.h>
using namespace std;
int fre[1010];
int main() {
  long long a, k, b, t, x, y, i, c = 0, n, gcd, lcm, f = 0;
  string s, str;
  cin >> t;
  k = 1;
  for (i = 1; i <= 1000; i++) {
    if (i % 10 == 3 || i % 3 == 0)
      continue;
    else
      fre[k] = i;
    k++;
  }
  fre[1000] = 1666;
  while (cin >> a) {
    cout << fre[a] << endl;
  }
  return 0;
}
