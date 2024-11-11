#include <bits/stdc++.h>
using namespace std;
const int maxn = 110000;
int n, m, P;
struct Tfind {
  int f[maxn];
  inline void build(int n) {
    for (int i = 1; i <= n; ++i) f[i] = i;
  }
  inline int find(int x) { return x != f[x] ? f[x] = find(f[x]) : x; }
  inline void add(int x, int y) { f[find(x)] = find(y); }
};
namespace Ninit {
void init() { cin >> n >> m >> P; }
}  // namespace Ninit
namespace Nsolve {
Tfind fnd;
int S[maxn], N, ans;
int a1, a2;
void solve() {
  fnd.build(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a1, &a2);
    fnd.add(a1, a2);
  }
  for (int i = 1; i <= n; ++i) ++S[fnd.find(i)];
  ans = 1;
  for (int i = 1; i <= n; ++i)
    if (S[i]) ++N, ans = (long long)ans * S[i] % P;
  if (N == 1) return cout << 1 << endl, void();
  for (int i = 0; i < N - 2; ++i) ans = (long long)ans * n % P;
  cout << ans << endl;
}
}  // namespace Nsolve
int main() {
  Ninit::init();
  Nsolve::solve();
  return 0;
}
