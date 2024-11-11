#include <bits/stdc++.h>
using namespace std;
long long int c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, t, x, y, z;
long long int mn = 8675435789, mx = -8675868757, PI = 3.14159265359,
              md = 1000000007, aa = 0, bb = 0, cc = 0;
string r, s, u, v, w;
long long int a[3][100000] = {0}, b[250002];
map<long long int, long long int> mp, mq, m1, m2;
queue<long long int> qu, qe;
pair<long long int, long long int> pp[30030];
set<string> se, sa;
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  cin >> n >> q;
  while (q--) {
    cin >> x >> y;
    if (x == 1) {
      if (a[x][y]) {
        cc = cc - a[2][y - 1] - a[2][y] - a[2][y + 1];
        a[x][y] = 0;
      } else {
        cc = cc + a[2][y - 1] + a[2][y] + a[2][y + 1];
        a[x][y] = 1;
      }
    } else {
      if (a[x][y]) {
        cc = cc - a[1][y - 1] - a[1][y] - a[1][y + 1];
        a[x][y] = 0;
      } else {
        cc = cc + a[1][y - 1] + a[1][y] + a[1][y + 1];
        a[x][y] = 1;
      }
    }
    if (cc)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
