#include <bits/stdc++.h>
using namespace std;
int read() {
  int xx = 0, ff = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = xx * 10 + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
inline int lowbit(int x) { return x & -x; }
const int MOD = 1000000009, maxn = 2000010;
int N, a[maxn], f[maxn], cnt[maxn];
int mypow(int a, int b) {
  int re = 1;
  while (b) {
    if (b & 1) re = 1LL * re * a % MOD;
    b >>= 1;
    a = 1LL * a * a % MOD;
  }
  return re;
}
int get_cnt(int x) {
  int re = 0;
  while (x) {
    x -= lowbit(x);
    re++;
  }
  return re;
}
int main() {
  N = read();
  for (int i = 1; i <= N; i++) f[read()]++;
  for (int i = 0; i <= 19; i++)
    for (int j = 0; j <= 1000000; j++)
      if (j & (1 << i)) (f[j ^ (1 << i)] += f[j]) % MOD;
  for (int i = 0; i <= 1000000; i++) cnt[i] = get_cnt(i);
  int ans = 0;
  for (int i = 0; i <= 1000000; i++)
    if (cnt[i] & 1)
      ans = (1LL * ans - (mypow(2, f[i]) - 1)) % MOD;
    else
      ans = (1LL * ans + (mypow(2, f[i]) - 1)) % MOD;
  if (ans < 0) ans += MOD;
  printf("%d\n", ans);
  return 0;
}
