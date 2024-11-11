#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18);
template <class Ruby_Rose>
inline void read(Ruby_Rose &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
}
int n, buc[N + 5], fa[N + 5];
long long ans;
inline int getfa(int x) { return (fa[x] == x) ? x : fa[x] = getfa(fa[x]); }
inline void merge(int i, int j, int w) {
  if (buc[i] && buc[j]) {
    int fu = getfa(i), fv = getfa(j);
    if (fu == fv) return;
    ans += 1ll * (buc[fu] + buc[fv] - 1) * w;
    fa[fu] = fv, buc[fv] = 1;
  }
}
int main() {
  read(n);
  for (register int i = 1, qa; i <= n; i++) read(qa), buc[qa]++, ans -= qa;
  for (register int i = 0; i < N; i++) fa[i] = i;
  buc[N] = 1;
  for (register int i = (1 << 18) - 1; ~i; i--) {
    for (register int j = i;; j = ((j - 1) & i)) {
      merge(i ^ j, j, i);
      if (!j) break;
    }
    merge(i, N, i);
  }
  cout << ans << endl;
  return 0;
}
