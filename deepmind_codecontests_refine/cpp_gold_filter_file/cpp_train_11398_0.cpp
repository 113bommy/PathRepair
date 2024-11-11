#include <bits/stdc++.h>
using namespace std;
long long c[1005][105];
long long tenk[1005];
long long tenm[1005];
int main(int argc, const char* argv[]) {
  long long n, k, m;
  cin >> n >> k >> m;
  tenk[0] = tenm[0] = 1;
  for (int i = 1; i <= n; i++) {
    tenk[i] = (tenk[i - 1] * 10) % k;
    tenm[i] = (tenm[i - 1] * 10) % m;
  }
  for (int i = 1; i <= 9; i++) {
    c[1][i % k] += 1;
  }
  if (n == 1) {
    cout << c[n][0] % m << endl;
    return 0;
  }
  for (int i = 2; i < n; i++) {
    for (long long l = 0; l <= 9; l++) {
      for (long long j = 1; j < k; j++) {
        c[i][(j + l * tenk[i - 1]) % k] =
            (c[i][(j + l * tenk[i - 1]) % k] + c[i - 1][j]) % m;
      }
      if (l > 0) {
        c[i][(l * tenk[i - 1]) % k] = (c[i][(l * tenk[i - 1]) % k] + 1) % m;
      }
    }
  }
  for (long long l = 1; l <= 9; l++) {
    for (long long j = 1; j < k; j++) {
      c[n][(j + l * tenk[n - 1]) % k] =
          (c[n][(j + l * tenk[n - 1]) % k] + c[n - 1][j]) % m;
    }
    c[n][(l * tenk[n - 1]) % k] = (c[n][(l * tenk[n - 1]) % k] + 1) % m;
  }
  long long tot = 0;
  for (int i = 1; i < n; i++) {
    long long tmp = (tenm[n - i - 1] * 9) % m;
    tot = (tot + (c[i][0] * tmp) % m) % m;
  }
  tot = (tot + c[n][0]) % m;
  cout << tot << endl;
}
