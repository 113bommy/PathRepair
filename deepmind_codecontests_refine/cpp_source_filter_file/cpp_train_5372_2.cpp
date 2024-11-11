#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
int n, k, a[N];
int pre[N];
inline int mul(long long a, int b) {
  if ((a *= b) > k) a %= k;
  return a;
}
int t[N << 2];
void PushUp(int rt) { t[rt] = mul(t[rt << 1], t[rt << 1 | 1]); }
void Build(int a[], int l, int r, int rt) {
  if (l == r) {
    t[rt] = a[r] % k;
    return;
  }
  int m = (l + r) >> 1;
  Build(a, l, m, rt << 1);
  Build(a, m + 1, r, rt << 1 | 1);
  PushUp(rt);
}
int Qry(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return t[rt];
  int m = (l + r) >> 1;
  int res = 1;
  if (L <= m) res = mul(res, Qry(L, R, l, m, rt << 1));
  if (m < R) res = mul(res, Qry(L, R, m + 1, r, rt << 1 | 1));
  return res;
}
void Init() {
  for (int i = (1); i < (n + 1); ++i) scanf("%d", a + i);
  Build(a, 1, n, 1);
}
int Solve() {
  long long ans = 0;
  for (int l = (1); l < (n + 1); ++l) {
    int L = l, R = n + 1;
    while (L < R) {
      int M = L + (R - L >> 1);
      if (Qry(l, M, 1, n, 1) == 0)
        R = M;
      else
        L = M + 1;
    }
    if (L <= n && Qry(l, L, 1, n, 1) == 0) ans += n - L + 1;
  }
  return printf("%lld\n", ans);
}
int main() {
  while (~scanf("%d%d", &n, &k)) {
    Init();
    Solve();
  }
  return 0;
}
