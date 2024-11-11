#include <bits/stdc++.h>
using namespace std;
const int MN = 100005, P2 = (1 << 17), MTS = 2 * P2 + 5, inf = 1000000005,
          mod = 1000000007;
const long long INF = 1000000000000000005LL;
int ile[MN], pref[MN];
int T[MTS];
void maksuj(int p, int v) {
  p += P2;
  while (p) {
    T[p] = max(T[p], v);
    p >>= 1;
  }
}
int ask(int a, int b) {
  a += P2, b += P2;
  int ret = 0;
  while (a < b) {
    if (a & 1) ret = max(ret, T[a++]);
    if (!(b & 1)) ret = max(ret, T[b--]);
    a >>= 1, b >>= 1;
  }
  if (a == b) ret = max(ret, T[a]);
  return ret;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    ++ile[a];
    --ile[b + 1];
  }
  for (int i = 1; i <= m; ++i) ile[i] += ile[i - 1];
  for (int i = 1; i <= m; ++i) {
    pref[i] = ask(1, ile[i]) + 1;
    maksuj(ile[i], pref[i]);
  }
  for (int i = 0; i < MTS; ++i) T[i] = 0;
  int ans = 0;
  for (int i = m; i > 0; --i) {
    int suf = ask(1, ile[i]) + 1;
    maksuj(ile[i], suf);
    ans = max(ans, pref[i] + suf - 1);
  }
  printf("%d", ans);
}
