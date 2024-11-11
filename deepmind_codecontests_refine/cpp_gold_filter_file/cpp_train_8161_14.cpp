#include <bits/stdc++.h>
using namespace std;
long long mini, minj, maxi, maxj, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o,
    p, q, r, s, t, u, v, w, x, y, z, sum, aa[1007], bb[1007];
char c1, c2, c3, c4, c5, c6, c7, c8, c9, c0;
string s1, s2, s3, s4, s5, s6, s7, s8, s9, s0;
long double d1, d2, d3, d4, d5, d6, d7, d8, d9, d0;
set<char> sc1, sc2;
set<long long> sl1, sl2;
map<long long, long long> mll1, mll2, mll3;
pair<int, int> pr[107];
int main() {
  cin >> n >> k;
  a = n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (j != a)
        cout << 0 << " ";
      else if (j == a)
        cout << k << " ";
    }
    a--;
    cout << endl;
  }
  return 0;
}
