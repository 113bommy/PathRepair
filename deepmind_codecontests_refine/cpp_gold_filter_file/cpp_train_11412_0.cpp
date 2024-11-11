#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
template <typename T, typename U>
static void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static void amax(T &x, U y) {
  if (x < y) x = y;
}
inline uint32_t ifzero(int num) { return (num - 1) >> 31; }
inline int ifnotzero(int num) { return ~((num - 1) >> 31); }
int main() {
  int Q;
  while (~scanf("%d", &Q)) {
    vector<uint32_t> pos(100000), neg(100000);
    for (int ii = 0; ii < Q; ++ii) {
      int ty;
      scanf("%d", &ty);
      if (ty == 1) {
        int L;
        int R;
        int k;
        scanf("%d%d%d", &L, &R, &k), --L, --R;
        uint32_t *data = k > 0 ? pos.data() : neg.data();
        uint32_t b = abs(k) - 1;
        for (int(x) = (int)(L); (x) < (int)(R); ++(x)) {
          ((data[x] - 1 > b) && (data[x] = b + 1));
        }
      } else if (ty == 2) {
        int L;
        int R;
        scanf("%d%d", &L, &R), --L, --R;
        long long ans = 0;
        for (int(x) = (int)(L); (x) < (int)(R); ++(x)) {
          ans += (pos[x] + neg[x]) & ifnotzero(pos[x]) & ifnotzero(neg[x]);
        }
        printf("%lld\n", ans);
      } else
        abort();
    }
  }
  return 0;
}
