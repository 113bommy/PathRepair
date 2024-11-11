#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int maxn = int(-1);
int v6[] = {0, 0, 0, 0, 1, 2};
long long solve(long long n, long long m) {
  if (n > m) swap(n, m);
  if (n == 1) return m / 6 * 6 + v6[m % 6] * 2;
  if (n == 2) {
    if (m == 2) return 0;
    if (m == 3) return 4;
    if (m == 7) return 12;
    return n * m;
  }
  return n * m / 2 * 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T(1), cas(0);
  while (++cas, T--) {
    long long n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
  }
  return 0;
}
