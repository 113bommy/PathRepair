#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2e5 + 17;
const long long INF = 1e9 + 17;
const int MOD = 1e9 + 7;
int n, c, d, h = INF, l, delta;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &c, &d);
    if (d == 2)
      h = min(h, 1900 - delta);
    else
      l = max(l, 1900 - delta);
    delta += c;
  }
  if (l >= h) cout << "Impossible", exit(0);
  if (h == INF) cout << "Infinity", exit(0);
  cout << h + delta - 1;
  return 0;
}
