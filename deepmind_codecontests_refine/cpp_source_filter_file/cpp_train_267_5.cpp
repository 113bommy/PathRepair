#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, c, i, a, m, l, r;
  cin >> t >> i >> m >> a >> l;
  r = i;
  c = 1;
  t = t - r;
  while (t > 0) {
    c++;
    r = r + a;
    if (r > m) r = m;
    t = t + l - r;
    if (t < 0) t = 0;
    c++;
  }
  cout << c;
  return 0;
}
