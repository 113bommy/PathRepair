#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, m, n, tt, s, a[333333], b[333333], c[333333], d, e, t, nn,
    mm, ll;
map<long long, long long> y, x, z;
string p;
int main() {
  cin >> n >> m >> l >> k >> d >> e;
  if (max(abs(l - d), abs(k - e)) > 4) {
    cout << "Second";
    return 0;
  }
  d = abs(l - d);
  e = abs(k - e);
  if (d + e > 6) {
    cout << "Second";
    return 0;
  }
  cout << "First";
}
