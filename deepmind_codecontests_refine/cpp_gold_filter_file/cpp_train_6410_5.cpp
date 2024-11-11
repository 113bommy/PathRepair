#include <bits/stdc++.h>
using namespace std;
long long max(long long x, long long y) {
  if (x > y) return x;
  return y;
}
long long min(long long x, long long y) {
  if (x < y) return x;
  return y;
}
long long n, m, k, x, y;
long long a[101][101] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> x >> y;
  long long cycle_length;
  if (n < 2)
    cycle_length = m * n;
  else
    cycle_length = 2 * m * (n - 1);
  long long cycles = k / cycle_length;
  long long k1 = k - (max(0, cycles)) * cycle_length;
  for (long long i = 1; i <= n && k1 > 0; i++)
    for (long long j = 1; j <= m && k1 > 0; j++) {
      k1--;
      a[i][j]++;
    }
  for (long long i = n - 1; i >= 1 && k1 > 0; i--)
    for (long long j = 1; j <= m && k1 > 0; j++) {
      k1--;
      a[i][j]++;
    }
  long long minel = (long long)(1e9), maxel1 = 0, maxel2 = 0;
  for (long long j = 1; j <= m; j++) {
    minel = min(minel, min(a[1][j], a[n][j]));
    maxel2 = max(maxel2, max(a[1][j], a[n][j]));
  }
  if (n > 2)
    for (long long i = 2; i <= n - 1; i++)
      for (long long j = 1; j <= m; j++) maxel1 = max(maxel1, a[i][j]);
  else
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++) maxel1 = max(maxel1, a[i][j]);
  long long max_ask, min_ask, ask_me;
  min_ask = minel + cycles;
  ask_me = a[x][y] + cycles;
  if (n <= 2)
    max_ask = maxel2 + cycles;
  else
    max_ask = max(maxel2 + cycles, maxel1 + 2 * cycles);
  if (x != 1 && x != n) ask_me += cycles;
  cout << max_ask << " " << min_ask << " " << ask_me << endl;
  return 0;
}
