#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 13371337;
const int64_t K = 2;
vector<vector<int64_t> > mul(vector<vector<int64_t> > A,
                             vector<vector<int64_t> > B) {
  vector<vector<int64_t> > C(K + 1, vector<int64_t>(K + 1));
  for (int i = 1; i <= K; i++)
    for (int j = 1; j <= K; j++)
      for (int k = 1; k <= K; k++) {
        C[i][j] ^= (A[i][k] * B[k][j]);
      }
  return C;
}
vector<vector<int64_t> > pow(vector<vector<int64_t> > A, int64_t p) {
  if (p == 1) return A;
  if (p % 2) return mul(A, pow(A, p - 1));
  vector<vector<int64_t> > X = pow(A, p / 2);
  return mul(X, X);
}
int64_t fib(int64_t N, int64_t resp[]) {
  vector<int64_t> F1(K + 1);
  F1[1] = resp[0];
  F1[2] = resp[1];
  vector<vector<int64_t> > T(K + 1, vector<int64_t>(K + 1));
  T[1][1] = 1ll, T[1][2] = 1ll;
  T[2][1] = 1ll, T[2][2] = 0ll;
  if (N == 1) return 1ll;
  T = pow(T, N - 1);
  int64_t res = 0ll;
  for (int i = 1; i <= K; i++) res = res ^ (T[1][i] * F1[i]);
  return res;
}
int64_t solve(int64_t c, int64_t a, int64_t b) {
  int64_t pd[10];
  memset(pd, 0, sizeof pd);
  pd[0] = a;
  pd[1] = b;
  for (int i = 2; i <= c; i++) {
    pd[i] = pd[i - 1] ^ pd[i - 2];
  }
  return pd[c];
}
int main() {
  int64_t k, a, b, c, d;
  cin >> k;
  while (k--) {
    cin >> a >> b >> c;
    int64_t resp[] = {b, a};
    if (c >= 4)
      cout << fib(c - 3, resp) << endl;
    else
      cout << solve(c, a, b) << endl;
  }
  return 0;
}
