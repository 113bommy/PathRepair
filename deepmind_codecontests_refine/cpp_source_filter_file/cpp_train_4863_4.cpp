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
const long long N = 1000 * 1000 + 7;
long long test;
long long n;
long long a[N], b[N];
long long c;
vector<long long> g;
void solve() {
  cin >> n;
  for (long long i = 1; i <= (n); ++i) {
    string s;
    cin >> s;
    g.clear();
    for (auto it : s) {
      if (it == '(') {
        g.push_back(1);
      } else {
        if (g.empty()) {
          g.push_back(0);
          continue;
        }
        if (g.front() == 1) {
          g.pop_back();
        } else {
          g.push_back(0);
        }
      }
    }
    if (g.size() == 0) {
      c++;
      continue;
    }
    long long x = 0, y = 0;
    for (auto it : g) {
      x += (it == 1);
      y += (it == 0);
    }
    if (x > 0 && y > 0) continue;
    a[x]++;
    b[x]++;
  }
  long long res = 0;
  for (long long i = 1; i <= (3 * 100 * 1000); ++i) {
    res += a[i] * b[i];
  }
  res += c * c;
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
  for (long long i = 1; i <= test; i++) {
    solve();
  }
  return 0;
}
