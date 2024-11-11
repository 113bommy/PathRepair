#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
vector<long long int> g;
long long int mod = 1000000007;
int main() {
  long long int n, m, k, a, b;
  cin >> n >> m >> k;
  g.resize(n, 0);
  long long int to = n, from = 0;
  for (long long int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    if (b - a <= k && b > a + 1) {
      cout << 0;
      return 0;
    }
    if (b - a > k && b - a - k > 1) {
      cout << 0;
      return 0;
    }
    if (b - a > 1 && to <= a) {
      cout << 0;
      return 0;
    }
    if (b - a > 1) g[a]++, to = min(to, b);
  }
  for (long long int i = 0; i < n; i++) {
    if (g[i]) from = max(from, i - k);
  }
  vector<long long int> two(n + 1, 1);
  for (long long int i = 1; i <= n; i++) two[i] = (two[i - 1] * 2) % mod;
  long long int count = 0, ans = 1;
  vector<long long int> d(n + 1, 0);
  to = min(n, to + k + 1);
  for (long long int i = from; i < to; i++) {
    if (i - (k + 1) >= from && !g[i] && !g[i - (k + 1)]) {
      ans = (ans + two[count - d[i - (k + 1)]]);
      ans = ans % mod;
    }
    if (i - (k + 1) >= from && !g[i] && !g[i - (k + 1)]) {
      count++;
    }
    d[i] = count;
  }
  cout << ans % mod;
}
