#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool umx(T& A, const T& B) {
  return A < B ? A = B, 1 : 0;
}
template <class T>
inline bool umn(T& A, const T& B) {
  return A > B ? A = B, 1 : 0;
}
const int INF = 0x3f3f3f3f;
const int maxn = 100010;
int n;
int a[maxn], pre[maxn], pos[maxn], r[maxn], v[maxn];
int main() {
  scanf("%d", &n);
  for (int i = (1), i_end_ = (n + 1); i < i_end_; ++i) {
    scanf("%d", a + i);
    pre[i] = pos[a[i]];
    pos[a[i]] = i;
    r[i] = i;
    v[i] = 0;
  }
  for (int k = (1), k_end_ = (n + 1); k < k_end_; ++k) {
    int t = 0;
    for (int i = 1; i <= n;) {
      ++t;
      int ri = r[i] + 1, vi = v[i] + (pre[r[i]] < i);
      while (ri <= n && vi <= k) {
        vi += pre[ri] < i;
        ++ri;
      }
      if (vi > k) --ri, --vi;
      r[i] = ri, v[i] = vi;
      i = ri;
    }
    printf("%d ", t);
  }
  putchar('\n');
  return 0;
}
