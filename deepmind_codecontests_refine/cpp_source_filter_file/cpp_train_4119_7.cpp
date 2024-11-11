#include <bits/stdc++.h>
using namespace std;
int n, m;
long double prob[128], M[128][128], ans[128][128], aux[128][128];
void multi(long double a[128][128], long double b[128][128]) {
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 128; j++) {
      aux[i][j] = 0;
      for (int k = 0; k < 128; k++) {
        aux[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  for (int i = 0; i < 128; i++)
    for (int j = 0; j < 128; j++) a[i][j] = aux[i][j];
}
void solve() {
  for (int i = 0; i < 128; i++)
    for (int j = 0; j < 128; j++) {
      M[i][j] = (i ^ j) <= n ? prob[i ^ j] : 0;
      ans[i][j] = (i == j ? 1 : 0);
    }
  while (m) {
    if (m % 2 == 1) {
      multi(ans, M);
    }
    multi(M, M);
    m /= 2;
  }
}
int main() {
  cin >> n >> m;
  swap(n, m);
  for (int i = 0; i < n; i++) cin >> prob[i];
  solve();
  cout << setprecision(20) << fixed;
  cout << 1 - ans[0][0] << endl;
}
