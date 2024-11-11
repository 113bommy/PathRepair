#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100000;
int n, m, An, Bn, Cn;
int U[maxn], C[maxn], D[maxn];
struct Tfind {
  int F[maxn], S[maxn];
  void set(int n) {
    int i;
    for (i = 0; i <= n + 1; ++i) F[i] = i;
  }
  int find(int x) { return x != F[x] ? F[x] = find(F[x]) : x; }
  inline void add(int a, int b) { F[find(a)] = find(b); }
} fnd;
namespace Ninit {
void init() {
  int i, ai, bi;
  scanf("%d%d", &n, &m);
  fnd.set(n), An = n, Bn = 0;
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &ai, &bi);
    U[ai] = U[bi] = 1;
    (++D[ai]) & 1 ? ++Bn : --Bn;
    (++D[bi]) & 1 ? ++Bn : --Bn;
    if (fnd.find(ai) != fnd.find(bi)) fnd.add(ai, bi), --An;
  }
  for (i = 1; i <= n; ++i)
    if (!U[i]) --An;
  for (Cn = An, i = 1; i <= n; ++i) C[fnd.find(i)] |= D[i] & 1;
  for (i = 1; i <= n; ++i)
    if (U[i] && fnd.find(i) == i && !C[i]) --Cn;
  if (!U[1]) ++An;
}
}  // namespace Ninit
namespace Nsolve {
void solve() {
  cout << An - 1 +
              (Bn + (Cn > 2    ? -2 * (Cn - 2) - 2
                     : Cn == 1 ? 0
                     : An > 1  ? 2
                               : 0)) /
                  2
       << endl;
}
}  // namespace Nsolve
int main() {
  Ninit::init();
  Nsolve::solve();
  return 0;
}
