#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long m, a(0);
  cin >> n >> m;
  int c[n], w[n], ansc[n];
  for (int ___(0); ___ < n; ++___) cin >> c[___];
  for (int ___(0); ___ < n; ++___) cin >> w[___];
  memset(ansc, 0, sizeof ansc);
  set<pair<int, int> > pay;
  for (int i(0); i < n; ++i) {
    if (!(c[i] % 100)) continue;
    if (m >= c[i] % 100) {
      pay.insert(make_pair((100 - c[i] % 100) % 100 * w[i], i));
      m -= c[i] % 100;
    } else if (!pay.empty() &&
               pay.begin()->first < (100 - c[i] % 100) % 100 * w[i]) {
      a += pay.begin()->first;
      m += 100;
      pay.erase(pay.begin());
      pay.insert(make_pair((100 - c[i] % 100) % 100 * w[i], i));
      m -= c[i] % 100;
    } else {
      a += (100 - c[i] % 100) % 100 * w[i];
      m += (100 - c[i] % 100) % 100;
    }
  }
  cout << a << '\n';
  for (set<pair<int, int> >::iterator i(pay.begin()); i != pay.end(); ++i)
    ansc[i->second] = c[i->second] % 100;
  for (int i(0); i < n; ++i)
    if (ansc[i])
      cout << c[i] / 100 << ' ' << ansc[i] << '\n';
    else
      cout << c[i] / 100 + (c[i] % 100 ? 1 : 0) << " 0\n";
}
