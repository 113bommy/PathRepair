#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, m, n, s, a[1111111], b[1111111], c, cc, d, e, f, t;
string p, r, q, w;
map<long long, long long> x[333333], y, z;
vector<long long> u, uu;
int main() {
  cin >> n >> p;
  l = p.size();
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i <= n; i++) {
    if (p[j] == '>') {
      j = j + a[j];
      if (j >= n) {
        cout << "FINITE";
        return 0;
      }
    } else {
      j = j - a[j];
      if (j < 0) {
        cout << "FINITE";
        return 0;
      }
    }
  }
  cout << "INFINITE";
}
