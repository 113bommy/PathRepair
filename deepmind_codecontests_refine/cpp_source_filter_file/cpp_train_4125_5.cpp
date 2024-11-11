#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
const long long MOD = 1e9 + 7;
const int MAXD = 102;
long long A[MAXD][MAXD];
long long C[MAXD][MAXD];
long long res[MAXD][MAXD];
void matMul(long long A[MAXD][MAXD], long long B[MAXD][MAXD],
            long long res[MAXD][MAXD], int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      C[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        C[i][j] = C[i][j] + (A[i][k] * B[k][j]) % MOD;
        if (C[i][j] >= MOD) {
          C[i][j] -= MOD;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = C[i][j];
    }
  }
}
void matExpo(long long A[MAXD][MAXD], long long b, long long res[MAXD][MAXD],
             int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = (i == j);
    }
  }
  while (b) {
    if (b & 1) {
      matMul(res, A, res, n);
    }
    matMul(A, A, A, n);
    b = b / 2ll;
  }
}
long long c1[MAXD], c2[MAXD], c3[MAXD];
long long fl[MAXD];
long long w1[1000001];
long long w2[1000001];
long long w3[1000001];
int main(int argc, char* argv[]) {
  io();
  int n, l, m;
  cin >> n >> l >> m;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    a %= m;
    w1[i] = a;
    c1[a]++;
  }
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    a %= m;
    w2[i] = a;
    c2[a]++;
  }
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    a %= m;
    w3[i] = a;
    c3[a]++;
  }
  if (l == 1) {
    long long fans = 0;
    for (int i = 1; i <= n; i++) {
      if ((w1[i] + w3[i]) % m == 0) {
        fans++;
      }
    }
    cout << fans << '\n';
    return 0;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      A[i][j] = c2[(m + i - j) % m];
    }
  }
  matExpo(A, l - 2, res, m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      fl[i] = fl[i] + res[i][j] * c1[j];
      if (fl[i] >= MOD) fl[i] %= MOD;
    }
  }
  long long fans = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = (m + m - w2[i] - w3[i]) % m;
    fans += fl[tmp];
    if (fans >= MOD) fans -= tmp;
  }
  cout << fans << '\n';
  return 0;
}
