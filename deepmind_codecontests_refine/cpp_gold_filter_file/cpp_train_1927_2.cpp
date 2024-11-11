#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, k, X[N], Y[N];
string sig[N];
long long F[75][75];
int order(int z, int L, int R, int Rem1, int Rem2) {
  if (z < L || z > R) return -1;
  if (z == Rem1 || z == Rem2) return 0;
  return 1;
}
bool cmp(int x, int y, string z) {
  if (z == "=") return x == y;
  if (z == "<") return x < y;
  if (z == ">") return x > y;
  if (z == ">=") return x >= y;
  if (z == "<=") return x <= y;
}
bool able(int L, int R, int Rem1, int Rem2) {
  for (int i = 1; i <= k; ++i) {
    int oX = order(X[i], L, R, Rem1, Rem2);
    int oY = order(Y[i], L, R, Rem1, Rem2);
    if (oX != 0 && oY != 0) continue;
    if (cmp(oX, oY, sig[i]) == 0) {
      return 0;
    }
  }
  return 1;
}
long long Solve(int L, int R) {
  long long& res = F[L][R];
  if (res != -1) return res;
  res = 0;
  if (L + 1 == R) {
    if (able(L, R, L, R)) {
      ++res;
    }
    return res;
  }
  if (able(L, R, L, R)) res += Solve(L + 1, R - 1);
  if (able(L, R, R - 1, R)) res += Solve(L, R - 2);
  if (able(L, R, L, L + 1)) res += Solve(L + 2, R);
  return res;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) cin >> X[i] >> sig[i] >> Y[i];
  n *= 2;
  memset(F, -1, sizeof(F));
  cout << Solve(1, n);
}
