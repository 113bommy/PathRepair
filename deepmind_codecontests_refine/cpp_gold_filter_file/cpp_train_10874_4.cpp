#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
int F[2005][2005];
const int Mod = 1e9 + 7;
int main() {
  int n, h;
  scanf("%d%d", &n, &h);
  vector<int> A(n + 1);
  for (int i = (1); i <= (n); ++i) scanf("%d", &A[i]);
  auto addMod = [](int& x, int y) { x = (x + y) % int(1e9 + 7); };
  F[0][0] = 1;
  for (int i = 0; i < n; i++) {
    int j = h - A[i + 1];
    if (j < 0) return !printf("0\n");
    int v = F[i][j];
    addMod(F[i + 1][j], v);
    if (j) addMod(F[i + 1][j - 1], 1LL * v * j % Mod);
    j = h - A[i + 1] - 1;
    if (j < 0) continue;
    v = F[i][j];
    addMod(F[i + 1][j], 1LL * v * (j + 1) % Mod);
    if (j < n) addMod(F[i + 1][j + 1], v);
  }
  printf("%d\n", F[n][0]);
}
