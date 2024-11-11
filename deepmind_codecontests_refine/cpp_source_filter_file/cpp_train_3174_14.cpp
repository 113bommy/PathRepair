#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T Rint(T &r) {
  int b = 1, c = getchar();
  r = 0;
  while (c < '0' || '9' < c) b = c == '-' ? -1 : b, c = getchar();
  while ('0' <= c && c <= '9')
    r = (r << 1) + (r << 3) + (c ^ '0'), c = getchar();
  return r *= b;
}
const int N = 1e5 + 10;
int n, m;
int aryx[N], stk[N], flef[N], frig[N];
long long aryd[N];
int main() {
  Rint(n);
  for (int i = 0; i <= n + 1; i++) Rint(aryx[i]);
  for (int i = 1; i <= n; i++) Rint(aryd[i]);
  aryd[0] = aryd[n + 1] = 1e9 + 7;
  stk[m = 1] = 0;
  for (int i = 1; i <= n + 1; i++) {
    while (m > 1 && 2 * aryd[stk[m]] < aryx[i] - aryx[stk[m - 1]]) m--;
    flef[i] = aryx[stk[m]];
    stk[++m] = i;
  }
  stk[m = 1] = n + 1;
  for (int i = n; ~i; i--) {
    while (m > 1 && 2 * aryd[stk[m]] < aryx[stk[m - 1]] - aryx[i]) m--;
    frig[i] = aryx[stk[m]];
    stk[++m] = i;
  }
  if (flef[n + 1]) {
    printf("%f\n", 0.0);
    return 0;
  }
  stk[m = 1] = 0;
  int ans = aryx[n + 1] - aryx[0];
  for (int i = 1; i <= n + 1; i++) {
    int nL = 1, nR = m;
    while (nL + 1 < nR) {
      int nM = (nL + nR) >> 1;
      if (flef[stk[nM]] + 2 * aryd[stk[nM]] >= frig[i] - 2 * aryd[i])
        nL = nM;
      else
        nR = nM;
    }
    int it = 0;
    if (flef[stk[nR]] + 2 * aryd[stk[nR]] >= frig[i] - 2 * aryd[i])
      it = stk[nR];
    else if (flef[stk[nL]] + 2 * aryd[stk[nL]] >= frig[i] - 2 * aryd[i])
      it = stk[nL];
    if (frig[i] - 2 * aryd[i] < aryx[i]) ans = min(ans, aryx[i] - aryx[it]);
    if (flef[i] + 2 * aryd[i] > aryx[i]) {
      while (m && 2 * aryd[i] + flef[i] >= aryd[stk[m]] + flef[stk[m]]) m--;
      stk[++m] = i;
    }
  }
  printf("%f\n", ans / 2.0);
  return 0;
}
