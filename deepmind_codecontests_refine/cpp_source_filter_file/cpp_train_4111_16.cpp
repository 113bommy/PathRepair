#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int LOG = 20;
int n;
long long ans;
int a[N], cnt[N];
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
namespace rmq {
int Max[N][LOG], Min[N][LOG], lg[N];
inline int querymax(int l, int r) {
  int k = lg[r - l + 1];
  return max(Max[l][k], Max[r - (1 << k) + 1][k]);
}
inline int querymin(int l, int r) {
  int k = lg[r - l + 1];
  return min(Min[l][k], Min[r - (1 << k) + 1][k]);
}
inline void init() {
  for (int i = 1; i <= n; ++i) lg[i] = (int)((double)log(i) / log(2.0));
  for (int i = 1; i <= n; ++i) Max[i][0] = Min[i][0] = a[i];
  for (int t = 1; t < LOG; ++t)
    for (int i = 1, j = (1 << (t - 1)) + 1; j <= n; ++i, ++j) {
      Max[i][t] = max(Max[i][t - 1], Max[j][t - 1]);
      Min[i][t] = min(Min[i][t - 1], Min[j][t - 1]);
    }
  return;
}
};  // namespace rmq
inline void solve(int l, int r) {
  int mid = (l + r) >> 1;
  if (l == r) return;
  solve(l, mid), solve(mid + 1, r);
  for (int i = mid, Min = a[i], Max = a[i], pos = mid; i >= l; --i) {
    chkmin(Min, a[i]);
    chkmax(Max, a[i]);
    while (pos + 1 <= r && a[pos + 1] > Min && a[pos + 1] < Max) ++pos;
    int j = i + Max - Min;
    ans += j > mid && j <= pos && rmq ::querymin(i, j) == Min &&
           rmq ::querymax(i, j) == Max;
  }
  for (int i = mid + 1, Min = a[i], Max = a[i], pos = mid + 1; i <= r; ++i) {
    chkmin(Min, a[i]);
    chkmax(Max, a[i]);
    while (pos - 1 >= l && a[pos - 1] > Min && a[pos - 1] < Max) --pos;
    int j = i - Max + Min;
    ans += j <= mid && j >= pos && rmq ::querymin(j, i) == Min &&
           rmq ::querymax(j, i) == Max;
  }
  int pa = mid, pb = mid + 1;
  for (int i = mid, Min = a[i], Max = a[i], pos = mid; i >= l; --i) {
    chkmin(Min, a[i]);
    chkmax(Max, a[i]);
    while (pa + 1 <= r && a[pa + 1] < Max) {
      ++pa;
      ++cnt[rmq ::querymin(mid + 1, pa) + pa];
    }
    while (pb <= r && rmq ::querymin(i, pb) == Min) {
      --cnt[rmq ::querymin(mid + 1, pb) + pb];
      ++pb;
    }
    if (pb <= pa) ans += cnt[Max + i];
  }
  if (pb <= pa) {
    for (int i = pb; i <= pa; ++i) --cnt[i + rmq ::querymin(mid + 1, i)];
  } else {
    for (int i = pa + 1; i <= pb - 1; ++i)
      ++cnt[i + rmq ::querymin(mid + 1, i)];
  }
  pa = mid, pb = mid + 1;
  for (int i = mid, Min = a[i], Max = a[i], pos = mid; i >= l; --i) {
    chkmin(Min, a[i]);
    chkmax(Max, a[i]);
    while (pa + 1 <= r && a[pa + 1] > Min) {
      ++pa;
      ++cnt[n + pa - rmq ::querymax(mid + 1, pa)];
    }
    while (pb <= r && rmq ::querymax(i, pb) == Max) {
      --cnt[n + pb - rmq ::querymax(mid + 1, pb)];
      ++pb;
    }
    if (pb <= pa) ans += cnt[n + i - Min];
  }
  if (pb <= pa) {
    for (int i = pb; i <= pa; ++i) --cnt[n + i - rmq ::querymax(mid + 1, i)];
  } else {
    for (int i = pa + 1; i <= pb - 1; ++i)
      ++cnt[n + i - rmq ::querymax(mid + 1, i)];
  }
  return;
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    read(x), read(y);
    a[x] = y;
  }
  rmq ::init();
  ans = n;
  solve(1, n);
  printf("%lld\n", ans);
  return 0;
}
