#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 2e5 + 10, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int casenum, casei;
int n;
long long a[N];
int v[N];
int main() {
  while (~scanf("%d", &n)) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    int ans = 0;
    int k = 1;
    while (k <= n) {
      ++ans;
      int l = k;
      while (a[l] == -1) ++l;
      int r = l + 1;
      while (a[r] == -1) ++r;
      if (r > n) break;
      int dif = a[r] - a[l];
      int dis = r - l;
      int d = dif / dis;
      if (dif % dis || a[r] - d * (r - k) <= 0) {
        k = r;
        continue;
      }
      for (k = r + 1; k <= n && (a[k] == -1 || a[k] - a[r] == d * (k - r)) &&
                      a[r] + d * (k - r) > 0;
           ++k)
        ;
    }
    printf("%d\n", ans);
  }
  return 0;
}
