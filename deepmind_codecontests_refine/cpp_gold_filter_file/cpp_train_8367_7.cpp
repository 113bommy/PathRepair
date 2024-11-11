#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N], Ins[N], Int[N];
struct BIT {
  int Sum[N];
  inline int lowbit(int x) { return x & (-x); }
  inline void Modify(int x) {
    for (; x; x -= lowbit(x)) Sum[x]++;
  }
  inline int Query(int x) {
    int ans = 0;
    for (; x <= N - 5; x += lowbit(x)) ans += Sum[x];
    return ans;
  }
} T;
inline int read() {
  int x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') flag = -1, ch = getchar();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
  return x * flag;
}
int main() {
  int n = read();
  for (int i = (1), iend = (n); i <= iend; i++) {
    int x = read(), y = read();
    a[x] = y, a[y] = x;
  }
  long long ans = 1ll * n * (n - 1) * (n - 2) / 6, cnt1 = 0, cnt2 = 0;
  for (int i = (1), iend = (n << 1); i <= iend; i++)
    if (a[i] < i) {
      Ins[i] = T.Query(a[i]), T.Modify(a[i]);
      Int[i] = i - a[i] - 1 - Ins[i] * 2;
      cnt1 += 1ll * Int[i] * (n - Int[i] - 1);
      cnt2 += 1ll * Ins[i] * (n - Int[i] - 1 - Ins[i]);
    }
  printf("%lld\n", ans - cnt1 / 2 - cnt2);
  return 0;
}
