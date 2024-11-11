#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1000 * 1000 * 1000 + 7;
constexpr long long inf = 1e9;
long long h1, h2;
long long a, b;
bool check(long long day) {
  if (h1 >= h2) return true;
  long long h = h1 + 12ll * day * (a - b);
  h += 8ll * a;
  return (h >= h2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h1 >> h2 >> a >> b;
  if (!check(0) && a <= b)
    cout << -1 << endl;
  else {
    long long lo = -1;
    long long hi = check(0) ? 0 : inf;
    while (lo + 1 != hi) {
      long long mid = (lo + hi) / 2ll;
      if (check(mid))
        hi = mid;
      else
        lo = mid;
    }
    cout << hi << endl;
  }
  return 0;
}
