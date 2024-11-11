#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9, mod = 1e9 + 7, inf = 1e18;
int ch(int a) {
  int ret = 0;
  while (a > 0) {
    ret = max(ret, a % 10);
    a /= 10;
  }
  return ret;
}
int main() {
  int a, b;
  cin >> a >> b;
  int mx = ch(a);
  mx = max(mx, ch(b));
  int bs = ++mx;
  int md = 0, cnt = 0;
  while (a > 0 && b > 0) {
    md += (a % 10 + b % 10);
    a /= 10;
    b /= 10;
    cnt++;
    md /= bs;
  }
  if (md) cnt++;
  cout << cnt << "\n";
}
