#include <bits/stdc++.h>
using namespace std;
const int MAXN = 107;
const int oo = 0x3f3f3f3f;
const long long loo = 4223372036854775807ll;
const long long mod = 1e9 + 7;
set<long long> se;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long b;
  while (cin >> b) {
    se.clear();
    long long q, l, m;
    cin >> q >> l >> m;
    for (long long i = 0; i < m; i++) {
      long long t;
      cin >> t;
      se.insert(t);
    }
    long long k = 0;
    int fuck = 0;
    while (b <= l && -b <= l) {
      fuck++;
      if (se.count(b) == 0) {
        k++;
      }
      b = b * q;
      if (fuck > 10000) {
        fuck = 0x3f3f3f3f;
        break;
      }
    }
    if (k < 1000)
      cout << k << endl;
    else
      cout << "inf" << endl;
  }
  return 0;
}
