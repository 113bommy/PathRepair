#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int infi = 1e9 + 7;
const long long infl = 1e18;
const long double eps = 1e-8;
const long double eps1 = 1e-10;
const int mod = (1e9 + 7);
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 7;
const long long p1 = 31;
const long long p2 = 37;
const long long p3 = 29;
const int ver1 = (62 * 62);
int used[100500];
int main() {
  int a, b, m, r;
  cin >> a >> b >> m >> r;
  for (int i = 1; i <= m; ++i) {
    int nr = (a * r + b) % m;
    if (used[nr]) {
      cout << i - used[nr];
      return 0;
    }
    used[nr] = i;
    r = nr;
  }
  return 0;
}
