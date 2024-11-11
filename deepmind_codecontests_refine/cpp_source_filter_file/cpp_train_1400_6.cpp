#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int N;
int X[206], Y[206];
int D[202][202];
long long area(int i1, int i2, int i3) {
  return 1LL * X[i1] * Y[i2] + 1LL * X[i2] * Y[i3] + 1LL * X[i3] * Y[i1] -
         1LL * Y[i1] * X[i2] - 1LL * Y[i2] * X[i3] - 1LL * Y[i3] * X[i1];
}
int sign(int i1, int i2, int i3) {
  long long val = area(i1, i2, i3);
  if (val < 0) return -1;
  if (val > 0) return 1;
  return 0;
}
bool inpoly(int x, int y) {
  int pnx = 1e8 + 8, pny = 1e8 + 9;
  X[N + 2] = x;
  Y[N + 2] = y;
  X[N + 3] = pnx;
  Y[N + 3] = pny;
  for (int i = 1; i <= N + 1; ++i) {
    X[i] *= 2;
    Y[i] *= 2;
  }
  int nn = 0;
  for (int i = 1; i <= N; ++i)
    if (sign(N + 2, N + 3, i) * sign(N + 2, N + 3, i + 1) == -1 &&
        sign(i, i + 1, N + 2) * sign(i, i + 1, N + 3) == -1)
      ++nn;
  for (int i = 1; i <= N + 1; ++i) {
    X[i] /= 2;
    Y[i] /= 2;
  }
  return (nn % 2);
}
bool isok(int i1, int i2) {
  if (i1 + 1 == i2 || (i1 == N && i2 == 1)) return true;
  for (int i = 1; i <= N; ++i)
    if (i != i1 && i != i2) {
      if (X[i] < min(X[i1], X[i2]) || X[i] > max(X[i1], X[i2])) continue;
      if (Y[i] < min(Y[i1], Y[i2]) || Y[i] > max(Y[i1], Y[i2])) continue;
      if (1LL * (Y[i] - Y[i1]) * (X[i2] - X[i]) ==
          1LL * (Y[i2] - Y[i]) * (X[i] - X[i1]))
        return false;
    }
  for (int i = 1; i <= N; ++i)
    if (i != i1 && i + 1 != i1 && (i + 1) % N != i1)
      if (i != i2 && i + 1 != i2 && (i + 1) % N != i2) {
        int p1 = i, p2 = i + 1;
        if (sign(i1, i2, p1) * sign(i1, i2, p2) == -1 &&
            sign(p1, p2, i1) * sign(p1, p2, i2) == -1)
          return false;
      }
  int xn = X[i1] + X[i2];
  int yn = Y[i1] + Y[i2];
  if (!inpoly(xn, yn)) return false;
  return true;
}
int ways(int i1, int i2) {
  if (D[i1][i2] != -1) return D[i1][i2];
  if (i1 + 1 == i2) return 1;
  int& now = D[i1][i2];
  now = 0;
  if (!isok(i1, i2)) return now;
  for (int k = i1 + 1; k <= i2 - 1; ++k)
    now = (now + 1LL * ways(i1, k) * ways(k, i2)) % MOD;
  return now;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> X[i] >> Y[i];
  X[N + 1] = X[1];
  Y[N + 1] = Y[1];
  memset(D, -1, sizeof(D));
  cout << ways(1, N) << '\n';
}
