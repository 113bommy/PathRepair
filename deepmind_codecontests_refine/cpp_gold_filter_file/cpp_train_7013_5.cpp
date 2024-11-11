#include <bits/stdc++.h>
using namespace std;
long long dp[55][55];
long double facts[55];
long long nck(int n, int k) {
  if (k > n) return 0;
  long long r = 1;
  for (int t = 1; t <= k; ++t) {
    r *= n;
    --n;
    r /= t;
  }
  return r;
}
int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for (int(i) = 0; (i) < (n); ++(i)) cin >> l[i];
  sort((l).begin(), (l).end());
  reverse((l).begin(), (l).end());
  int p;
  cin >> p;
  vector<long long> res(n, 0);
  int sum = 0;
  for (int(i) = 0; (i) < (n); ++(i)) sum += l[i];
  if (sum <= p) {
    cout << n << endl;
    return 0;
  }
  for (int(i) = 0; (i) < (n); ++(i)) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int(j) = 0; (j) < (n); ++(j))
      if (j != i) {
        for (int(x) = (p); (x) >= (0); --(x))
          for (int(y) = (n - 1); (y) >= (0); --(y))
            if (dp[x][y]) {
              if (x + l[j] <= p && y + 1 <= n - 1) {
                dp[x + l[j]][y + 1] += dp[x][y];
              }
            }
      }
    for (int(x) = (max(0, p - l[i] + 1)); (x) <= (p); ++(x))
      for (int(y) = (1); (y) <= (n - 1); ++(y)) {
        res[y] += dp[x][y];
      }
  }
  double avg = 0;
  for (int(y) = (1); (y) <= (n - 1); ++(y)) {
    avg += y * res[y] * 1.0 / nck(n - 1, y);
  }
  avg /= n;
  printf("%.6f", avg);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
