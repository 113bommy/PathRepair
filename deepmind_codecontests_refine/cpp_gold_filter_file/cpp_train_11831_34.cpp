#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
const int N = 5 * 100 * 1000 + 7;
int test;
int n;
string s, ss;
char t[] = {'a', 'e', 'i', 'o', '1', '3', '5', '7', '9', 'u'};
map<char, int> m;
void solve() {
  cin >> s;
  int res = 0;
  for (auto it : s) {
    for (int i = 0; i < (10); ++i) {
      if (it == t[i]) {
        res++;
      }
    }
  }
  cout << res;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
