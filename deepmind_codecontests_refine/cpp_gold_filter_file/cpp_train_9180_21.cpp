#include <bits/stdc++.h>
const int kInf = 0x3f3f3f3f, kMod = 1e9 + 7;
const long long kInf64 = 0x3f3f3f3f3f3f3f3f;
template <typename T>
inline void UMin(T& x, const T& y) {
  if (x > y) x = y;
}
template <typename T>
inline void UMax(T& x, const T& y) {
  if (x < y) x = y;
}
inline int Add(int a, int b) { return (a += b) >= kMod ? a - kMod : a; }
inline int Sub(int a, int b) { return (a -= b) < 0 ? a + kMod : a; }
inline int Mul(int a, int b) { return 1ll * a * b % kMod; }
int FPow(int bs, int ex = kMod - 2) {
  int res = 1;
  for (; ex; bs = Mul(bs, bs), ex >>= 1)
    if (ex & 1) res = Mul(res, bs);
  return res;
}
const int kMaxn = 3e5 + 5;
int n, m, tot, ans, sum[kMaxn << 1];
std::pair<int, int> anp = {1, 1};
char S[kMaxn];
void Gao(int, int);
int main() {
  scanf("%d%s", &n, S);
  m = kInf;
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + (S[i] == '(' ? 1 : -1);
    UMin(m, sum[i + 1]);
  }
  if (sum[n]) {
    puts("0\n1 1");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (sum[i] == m) ++tot;
    sum[i + n] = sum[i];
  }
  ans = tot;
  Gao(m + 2, tot);
  Gao(m + 1, 0);
  printf("%d\n%d %d\n", ans, anp.first, anp.second);
  return 0;
}
void Gao(int x, int d) {
  for (int cnt = 0, i = 1, l = 1; i <= (n << 1); ++i) {
    if (sum[i] == x) ++cnt;
    if (sum[i] < x) {
      cnt = 0, l = i + 1 > n ? i % n + 1 : i + 1;
    }
    if (d + cnt >= ans) {
      ans = d + cnt;
      anp = {l, i + 1 > n ? i % n + 1 : i + 1};
    }
  }
}
