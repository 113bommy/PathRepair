#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:20000007")
#pragma GCC optimize("unroll-loops")
const int N = (int)1e6 + 100;
const int maxn = (int)1e3 + 100;
const int base = (int)1e9;
const int mod = (int)1e9 + 7;
const int inf = INT_MAX;
const long long ll_inf = LLONG_MAX;
const long double PI = acos((long double)-1.0);
const long double eps = 1e-8;
void solve() {
  int n, w;
  cin >> n >> w;
  long long minw = 0, maxw = w, val = 0, ok = 1;
  for (int i = 0; i < n; ++i) {
    int e;
    cin >> e;
    val += e;
    if (val < 0 && -val > minw) minw = -val;
    if (w - val < maxw) maxw = w - val;
    if (ok && minw == maxw) cout << 0 << '\n', ok = 0;
  }
  ++maxw;
  if (ok) cout << maxw - minw << '\n';
}
int main() {
  int T = 1;
  for (; T; --T) solve();
  return 0;
}
