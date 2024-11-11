#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  if (n < 4) {
    if (n == 2)
      cout << 1;
    else
      cout << 0;
  } else {
    int l = 4, r = 5;
    while (r < n) {
      int tmpl, tmpr;
      if (l & 1)
        tmpl = r + l + 1, tmpr = r + r + 1;
      else
        tmpl = l + l + 1, tmpr = l + r + 1;
      l = tmpl, r = tmpr;
    }
    if (n == l || n == r)
      cout << 1;
    else
      cout << 0;
  }
  return 0;
}
