#include <bits/stdc++.h>
const int N = (1 << 13) + 5;
int n, bit[N], id[N], cnt, st[N];
long long a[20];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < (1 << 13); i++) bit[i] = bit[i >> 1] + (i & 1);
  for (int i = 1, cnt = 0; i < (1 << 13) && cnt < n; i++)
    if (bit[i] == 6) id[++cnt] = i;
  for (int i = 0; i < 13; i++) {
    int tp = 0;
    for (int j = 1; j <= n; j++)
      if (id[j] & (1 << i)) st[++tp] = j;
    if (!tp) continue;
    printf("? %d ", tp);
    for (int j = 1; j <= tp; j++) printf("%d ", st[j]);
    puts("");
    fflush(stdout);
    scanf("%lld", &a[i]);
  }
  printf("! ");
  for (int i = 1; i <= n; i++) {
    long long ans = 0;
    for (int j = 0; j < 13; j++) {
      if (id[i] & (1 << j)) continue;
      ans ^= a[j];
    }
    printf("%lld ", ans);
  }
}
