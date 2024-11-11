#include <bits/stdc++.h>
const int maxn = 2e5 + 100;
int cir[maxn];
int diag(int x, int n) { return x > n ? x - n : x + n; }
int main() {
  int n;
  scanf("%d", &n);
  if (!(n & 1)) return puts("NO") & 0;
  if (n == 1) return 0 & puts("YES\n1 2");
  cir[1] = 1;
  cir[n + 1] = 2;
  bool flag = 0;
  for (int i = n; i > 1; --i) cir[i] = cir[i + 1] + 1 + flag * 2, flag ^= 1;
  cir[n << 1] = 4;
  flag = 0;
  for (int i = (n << 1) - 1; i > n + 1; --i)
    cir[i] = cir[i + 1] + 1 + flag * 2, flag ^= 1;
  puts("YES");
  for (int i = 1; i <= n << 1; ++i) printf("%d ", cir[i]);
}
