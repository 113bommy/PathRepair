#include <bits/stdc++.h>
using namespace std;
namespace Ruri {
const int infi = 1e9;
const long long infl = 4e18;
}  // namespace Ruri
using namespace Ruri;
namespace Gadgets {
inline long long ceil_div(long long a, long long b) { return (a + b - 1) / b; }
inline long long pos_mod(long long a, long long b) { return (a % b + b) % b; }
}  // namespace Gadgets
namespace Read {
inline int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long rl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline double rd() {
  double x;
  scanf("%lf", &x);
  return x;
}
}  // namespace Read
namespace DeBug {}
using namespace Gadgets;
using namespace Read;
using namespace DeBug;
const int MAX_N = 2e5 + 5;
int n;
int a[MAX_N], b[MAX_N], m[MAX_N], t[MAX_N];
int mna[MAX_N], mxa[MAX_N];
int id[MAX_N];
int eat_a[MAX_N], eat_b[MAX_N];
int main() {
  t[0] = infi;
  int T = ri();
  while (T--) {
    n = ri();
    for (int i = 1, bbb = n; i <= bbb; ++i)
      a[i] = ri(), b[i] = ri(), m[i] = ri(), t[i] = a[i] + b[i] - m[i];
    for (int i = 1, bbb = n; i <= bbb; ++i)
      mna[i] = max(0, a[i] - m[i]), mxa[i] = a[i] - max(0, m[i] - b[i]);
    iota(id + 1, id + 1 + n, 1);
    sort(id + 1, id + 1 + n, [&](int x, int y) {
      if (t[x] != t[y]) return t[x] < t[y];
      return mna[x] != mna[y] ? mna[x] > mna[y] : mxa[x] > mxa[y];
    });
    int variety = 0, mn = 0;
    for (int i = 1, bbb = n; i <= bbb; ++i) {
      int now = id[i];
      if (t[now] != t[id[i - 1]]) {
        ++variety;
        eat_a[now] = a[now] - mna[now];
        eat_b[now] = m[now] - eat_a[now];
        mn = mna[now];
      } else {
        if (mxa[now] >= mn) {
          eat_a[now] = a[now] - mn;
          eat_b[i] = m[now] - eat_a[now];
        } else {
          ++variety;
          eat_a[now] = a[now] - mna[now];
          eat_b[now] = m[now] - eat_a[now];
          mn = mna[now];
        }
      }
    }
    printf("%d\n", variety);
    for (int i = 1, bbb = n; i <= bbb; ++i)
      printf("%d %d\n", eat_a[i], eat_b[i]);
  }
  return 0;
}
