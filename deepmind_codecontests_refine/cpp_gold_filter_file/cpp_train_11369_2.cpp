#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5, M = 1e6 + 5;
long long mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
long long infll = 1e18 + 7;
string s;
vector<string> a;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  string t = "";
  for (auto v : s) {
    t += v;
    if (v == '>') {
      a.push_back(t);
      t = "";
    }
  }
  a.push_back(t);
  long long x = 0;
  for (auto v : a) {
    if (v.length() == 4) x--;
    for (long long i = 0; i < 2 * x; i++) cout << ' ';
    cout << v << '\n';
    if (v.length() == 3) x++;
  }
}
