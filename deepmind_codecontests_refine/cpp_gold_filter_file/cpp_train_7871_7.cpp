#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300008;
const long long inf = 1000000001;
const long long INF = 2e18;
const long double EPS = 1e-7;
const long long mod = inf + 6;
const int moff = 998244353;
const int mod13 = 1000003;
const long double PI = acos(-1.0);
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<pair<char, int>> op(n);
  string kek;
  for (int i = 0; i < n; ++i) {
    string lol;
    cin >> lol;
    cin >> op[i].second;
    op[i].first = lol[0];
  }
  int orn = 0, xorn = 0, andn = 0;
  for (int bt = 0; bt < 10; ++bt) {
    int x = 0, y = 1;
    for (int i = 0; i < n; ++i) {
      if (op[i].first == '|' && (op[i].second & (1 << bt))) {
        x = y = 1;
      } else if (op[i].first == '^' && (op[i].second & (1 << bt))) {
        x ^= 1;
        y ^= 1;
      } else if (op[i].first == '&' && (op[i].second & (1 << bt))) {
        x &= 1, y &= 1;
      } else if (op[i].first == '&' && !(op[i].second & (1 << bt))) {
        x = 0, y = 0;
      }
    }
    if (x == 0 && y == 0) {
    } else {
      andn += (1 << bt);
      if (x == y) {
        orn += (1 << bt);
      } else if (x == 1) {
        xorn += (1 << bt);
      }
    }
  }
  cout << 3 << '\n';
  cout << '&' << ' ' << andn << '\n'
       << '|' << ' ' << orn << '\n'
       << '^' << ' ' << xorn << '\n';
}
