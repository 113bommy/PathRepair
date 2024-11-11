#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
long long int res[103][10];
long long int a[10];
long long newton[105][105];
void comptNewton() {
  for (int n = 0; n < 103; n++) {
    newton[n][0] = 1;
    newton[n][n] = 1;
  }
  for (int n = 1; n < 103; n++) {
    for (int k = 1; k < n; k++) {
      newton[n][k] = (newton[n - 1][k - 1] + newton[n - 1][k]) % MOD;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  comptNewton();
  int n;
  cin >> n;
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 10; i++) {
    for (int k = 0; k < 103; k++) {
      res[i][k] = 0;
    }
  }
  int s = a[9];
  for (int k = s; k <= n; k++) {
    res[9][k] = 1;
  }
  for (int i = 8; i > 0; i--) {
    s += a[i];
    for (int k = s; k <= n; k++) {
      for (int additional = 0; additional + s <= k; additional++) {
        res[i][k] += newton[k][additional + a[i]] *
                     res[i + 1][k - additional - a[i]] % MOD;
        res[i][k] %= MOD;
      }
    }
  }
  s += a[0];
  for (int k = s; k <= n; k++) {
    for (int additional = 0; additional + s <= k; additional++) {
      res[0][k] += newton[k - 1][additional + a[0]] *
                   res[1][k - additional - a[0]] % MOD;
      res[0][k] %= MOD;
    }
  }
  long long int r = 0;
  for (int i = 1; i <= n; i++) {
    r += res[0][i];
    r %= MOD;
  }
  cout << r << endl;
  return 0;
}
