#include <bits/stdc++.h>
using namespace std;
long long int c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, t, x, y, z;
long long int mn = 8675435789, mx = -8675868757, PI = 3.14159265359,
              md = 1000000007, aa = 0, bb = 0, cc = 0;
string r, s, u, v, w;
long long int a[250002], b[250002];
map<long long int, long long int> mp, mq;
queue<long long int> qu, qe;
pair<long long int, long long int> pp[30030];
set<string> se, sa;
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  cin >> t;
  while (t--) {
    cin >> x >> y >> z;
    if (x < z)
      p = 1;
    else
      p = -1;
    cc = y * x;
    if (cc > z)
      q = cc;
    else
      q = -1;
    cout << p << ' ' << q << endl;
  }
}
