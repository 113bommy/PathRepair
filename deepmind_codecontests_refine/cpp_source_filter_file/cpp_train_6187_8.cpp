#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const double EPS = 1e-9;
int mods(int a, int b) { return (b + (a % b)) % b; }
long long n, d[30500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  d[0] = 1;
  for (long long i = 1; i <= 30500000; i++) {
    d[i] = i * i + i * i;
    if (d[i] < 0) cout << d[i] << '\n';
  }
  cin >> n;
  if (!n) {
    cout << 1 << '\n';
    return 0;
  }
  auto pos = lower_bound(d, d + 30500001, n * n) - d;
  if (d[pos] != n * n) pos--;
  if (pos * pos + (pos + 1) * (pos + 1) <= n * n)
    cout << 2 * (2 * pos) + 2 * (2 * (pos + 1)) << '\n';
  else
    cout << 4 * (2 * pos) << '\n';
  return 0;
}
