#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp &x) {
  x = 0;
  char c = getchar();
  int f = 0;
  for (; c < '0' || c > '9'; f |= c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
const int N = 1e6 + 233;
int n, q, a[N];
char str[N];
inline void chkmax(int &x, int y) { x = max(x, y); }
namespace bit {
int ans[N], maxPre[N], dpPre[N], minSuf[N], dpSuf[N], Max[N], Min[N], sum[N];
inline void ps(int rt, bool print = false) {
  ans[rt] = max(ans[(rt << 1)], ans[(rt << 1 | 1)]);
  chkmax(ans[rt], dpPre[(rt << 1 | 1)] - minSuf[(rt << 1)]);
  chkmax(ans[rt], maxPre[(rt << 1 | 1)] + dpSuf[(rt << 1)]);
  sum[rt] = sum[(rt << 1)] + sum[(rt << 1 | 1)];
  maxPre[rt] = max(maxPre[(rt << 1)], sum[(rt << 1)] + maxPre[(rt << 1 | 1)]);
  minSuf[rt] =
      min(minSuf[(rt << 1 | 1)], sum[(rt << 1 | 1)] + minSuf[(rt << 1)]);
  dpPre[rt] =
      max(dpPre[(rt << 1)], max(dpPre[(rt << 1 | 1)] - sum[(rt << 1)],
                                maxPre[(rt << 1 | 1)] + Max[(rt << 1)]));
  dpSuf[rt] =
      max(dpSuf[(rt << 1 | 1)], max(sum[(rt << 1 | 1)] + dpSuf[(rt << 1)],
                                    Max[(rt << 1 | 1)] - minSuf[(rt << 1)]));
  Max[rt] = max(abs(sum[rt]), max(sum[(rt << 1 | 1)] + Max[(rt << 1)],
                                  Max[(rt << 1 | 1)] - sum[(rt << 1)]));
  Min[rt] = min(-abs(sum[rt]), min(sum[(rt << 1 | 1)] + Min[(rt << 1)],
                                   Min[(rt << 1 | 1)] - sum[(rt << 1)]));
  if (print) {
    cout << sum[(rt << 1 | 1)] + Min[(rt << 1)] << " " << Min[(rt << 1 | 1)]
         << " " << sum[(rt << 1)] << " " << Min[rt] << "\n";
  }
}
inline void modify(int l, int r, int rt, int x) {
  if (l == r) {
    ans[rt] = abs(a[x]);
    maxPre[rt] = max(0, a[x]);
    minSuf[rt] = min(0, a[x]);
    dpSuf[rt] = dpPre[rt] = Max[rt] = max(0, a[x]);
    Min[rt] = min(0, a[x]);
    sum[rt] = a[x];
    return;
  }
  x <= (l + (r - l) / 2) ? modify(l, (l + (r - l) / 2), (rt << 1), x)
                         : modify((l + (r - l) / 2) + 1, r, (rt << 1 | 1), x);
  ps(rt);
}
inline void debug(int l, int r, int rt) {
  cout << l << " " << r << " " << ans[rt] << " " << dpPre[rt] << " "
       << dpSuf[rt] << " " << maxPre[rt] << " " << minSuf[rt] << " " << Max[rt]
       << " " << Min[rt] << "\n";
  if (l == r) {
    return;
  }
  debug(l, (l + (r - l) / 2), (rt << 1));
  debug((l + (r - l) / 2) + 1, r, (rt << 1 | 1));
  if (l == 7 && r == 8) ps(rt, true);
}
}  // namespace bit
int main(void) {
  read(n);
  read(q);
  scanf("%s", str + 1);
  n = strlen(str + 1);
  for (register int i = 1; i <= (n); i++) a[i] = str[i] == '(' ? 1 : -1;
  for (register int i = 1; i <= (n); i++) bit::modify(1, n, 1, i);
  cout << bit::ans[1] << "\n";
  for (register int i = 1; i <= (q); i++) {
    int x, y;
    read(x);
    read(y);
    swap(a[x], a[y]);
    bit::modify(1, n, 1, x);
    bit::modify(1, n, 1, y);
    cout << bit::ans[1] << "\n";
  }
}
