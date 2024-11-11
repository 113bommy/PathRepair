#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 100005;
const int NBIT = 20;
int i, j, n, a[N], nextNr[N][NBIT], ans;
bool canObtain[10 * N];
void solve(int poz, int val) {
  if (poz > n) return;
  if (!canObtain[val]) canObtain[val] = 1, ++ans;
  int nextPoz = n + 1;
  for (int i = 0; i < NBIT; ++i)
    if (!(val & (1 << i))) nextPoz = min(nextPoz, nextNr[poz][i]);
  solve(nextPoz, val | a[nextPoz]);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  for (i = 0; i < NBIT; ++i) nextNr[n + 1][i] = n + 1;
  for (i = n; i; --i)
    for (j = 0; j < NBIT; ++j)
      if (a[i] & (1 << j))
        nextNr[i][j] = i;
      else
        nextNr[i][j] = nextNr[i + 1][j];
  for (i = 1; i <= n; ++i) solve(i, a[i]);
  printf("%d\n", ans);
  return 0;
}
