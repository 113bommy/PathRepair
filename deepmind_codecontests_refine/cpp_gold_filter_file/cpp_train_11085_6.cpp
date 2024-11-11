#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w,
    x, y, z, ed, maxi, maxj, mini, minj, sum, res;
long long aa[100007], bb[10007];
long double d1, d2, d3, d4, d5, d6, d7, d8, d9, d0;
string s1, s2, s3, s4, s5, s6, s7, s8, s9, s0;
set<long long> sl1, sl2, sl3;
set<string> ss1, ss2, ss3;
char c1, c2;
map<string, long long> msl1, msl2, msl3;
map<string, string> mss1, mss2, mss3;
map<char, long long> mcl1, mcl2, mcl3;
map<long long, long long> mll1, mll2, mll3;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    if (x == 1) a++;
    if (x == 2) b++;
    if (x == 3) c++;
  }
  if (a >= b && a >= c)
    cout << b + c << endl;
  else if (b >= a && b >= c)
    cout << a + c << endl;
  else if (c >= a && c >= b)
    cout << a + b << endl;
  return 0;
}
