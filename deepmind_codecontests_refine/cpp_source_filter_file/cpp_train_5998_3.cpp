#include <bits/stdc++.h>
using namespace std;
long long gi() {
  char cc = getchar();
  long long cn = 0, flus = 1;
  while (cc < '0' || cc > '9') {
    if (cc == '-') flus = -flus;
    cc = getchar();
  }
  while (cc >= '0' && cc <= '9') cn = cn * 10 + cc - '0', cc = getchar();
  return cn * flus;
}
const long long P = 1e9 + 7;
signed main() {
  long long n = gi(), m = gi();
  long long ans = 2 * (n + 1 - m) % P, f = 2 * (n + 1);
  for (register long long i = (2); i <= (n); ++i) ans = ans * f % P;
  cout << ans << endl;
  return 0;
}
