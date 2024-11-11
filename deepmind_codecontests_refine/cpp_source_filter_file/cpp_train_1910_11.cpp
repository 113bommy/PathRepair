#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MAXm = 300, MAXn = 1e6 + 100;
long long x[MAXm], y[MAXm];
int ans[MAXn];
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0, __e = m; i < __e; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= n; i++) ans[i] = 1;
  for (int i = 0, __e = m; i < __e; i++)
    for (int j = 0, __e = m; j < __e; j++)
      if (y[i] < y[j]) {
        long long dx = x[i] - x[j], dy = y[i] - y[j];
        long long g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        if (y[i] % abs(dy) != 0) continue;
        long long a = dx * (y[i] / dy) + x[i];
        if (a > n || a < 1) continue;
        int c = 0;
        for (int k = 0, __e = m; k < __e; k++) {
          if (dx == 0) {
            if (x[k] == x[i]) c++;
          } else {
            if ((x[k] - x[i]) % abs(dx) != 0 || (y[k] - y[i]) % abs(dy) != 0)
              continue;
            if ((x[k] - x[i]) / dx == (y[k] - y[i]) / dy) c++;
          }
        }
        ans[a] = max(ans[a], c);
      }
  long long sum = 0;
  for (int i = 1; i <= n; i++) sum += ans[i];
  cout << sum << endl;
  return 0;
}
