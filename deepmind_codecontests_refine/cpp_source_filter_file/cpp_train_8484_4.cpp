#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long x[105];
double f[105][1005];
double sum[10010];
inline void read() {
  cin >> n >> m;
  for (long long i = 0; i <= n - 1; i++) {
    cin >> x[i];
  }
}
inline void solve() {
  long long ms = n * m;
  if (m == 1) {
    puts("1");
    return;
  }
  f[0][0] = 1;
  for (long long i = 0; i <= n - 1; i++) {
    for (long long s = 0; s <= ms; s++) {
      if (s) {
        sum[s] = sum[s - 1] + f[i][s];
      } else {
        sum[s] = f[i][s];
      }
      if (s > m) {
        f[i + 1][s] = sum[s - 1] - sum[s - m - 1];
      } else {
        f[i + 1][s] = sum[s - 1];
      }
      if (s >= x[i]) {
        f[i + 1][s] -= f[i][s - x[i]];
      }
      f[i + 1][s] /= (m - 1);
    }
  }
  long long score = 0;
  for (long long i = 0; i <= n - 1; i++) {
    score += x[i];
  }
  double prob = 0;
  for (long long s = 0; s <= score - 1; s++) {
    prob += f[n][s];
  }
  prob *= (m - 1);
  prob += 1.0;
  cout.precision(20);
  cout << fixed << prob;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  read();
  solve();
  return 0;
}
