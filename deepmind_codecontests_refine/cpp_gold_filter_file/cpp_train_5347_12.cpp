#include <bits/stdc++.h>
using namespace std;
long long modd = 1000000007;
vector<vector<long long> > comb(105, vector<long long>(105, 1));
long long po(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long tmp = po(a, b / 2);
  tmp = (tmp * tmp) % modd;
  if (b % 2 == 1) {
    tmp = (tmp * a) % modd;
  }
  return tmp;
}
int main() {
  int n, k;
  long long m;
  scanf("%d %I64d %d", &n, &m, &k);
  for (int i = 2; i < 105; i++) {
    for (int j = 1; j < i; j++) {
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % modd;
    }
  }
  vector<long long> app(n);
  long long smallest = 1000000000000000100;
  long long biggest = -1;
  for (int i = 0; i < n; i++) {
    app[i] = m / n;
    if ((i + 1) <= m % n) {
      app[i]++;
    }
    smallest = min(smallest, app[i]);
    biggest = max(biggest, app[i]);
  }
  vector<vector<long long> > powers(2, vector<long long>(n + 1));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0) {
        powers[i][j] = po(comb[n][j], smallest);
      } else {
        powers[i][j] = po(comb[n][j], biggest);
      }
    }
  }
  vector<vector<long long> > dp(n, vector<long long>(k + 1, 0));
  for (int i = 0; i <= min(n, k); i++) {
    if (app[0] == smallest) {
      dp[0][i] = powers[0][i];
    } else {
      dp[0][i] = powers[1][i];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int sum = 0; sum <= min(k, (i + 1) * n); sum++) {
      int j = sum;
      for (int last_used = 0; last_used <= min(k, min(sum, n)); last_used++) {
        if (app[i] == smallest) {
          dp[i][j] =
              (dp[i][j] +
               (dp[i - 1][j - last_used] * powers[0][last_used]) % modd) %
              modd;
        } else if (app[i] == biggest) {
          dp[i][j] =
              (dp[i][j] +
               (dp[i - 1][j - last_used] * powers[1][last_used]) % modd) %
              modd;
        }
      }
    }
  }
  printf("%I64d\n", dp[n - 1][k]);
  return 0;
}
