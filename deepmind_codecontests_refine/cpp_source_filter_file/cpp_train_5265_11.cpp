#include <bits/stdc++.h>
using namespace std;
const int _ = 1e2;
const int maxn = 1e3 + _;
int as[maxn], sc[maxn], len, num[maxn];
int main() {
  int n;
  scanf("%d", &n);
  memset(as, 63, sizeof(as));
  for (int w = 0; w <= 9; w++)
    for (int x = 0; x <= 1; x++) {
      len = 0;
      for (int i = 0; i < n; i++)
        if (((i & (1 << w - 1)) == 0) ^ (x == 0)) num[++len] = i;
      if (len == 0 || len == n) continue;
      printf("%d\n", len);
      for (int i = 1; i <= len; i++) printf("%d ", num[i] + 1);
      puts("");
      fflush(stdout);
      for (int i = 0; i < n; i++) scanf("%d", &sc[i]);
      for (int i = 0; i < n; i++)
        if (((i & (1 << w - 1)) == 0) ^ (x == 1)) as[i] = min(as[i], sc[i]);
    }
  puts("-1");
  for (int i = 0; i < n; i++) printf("%d ", as[i]);
  puts("");
  fflush(stdout);
  return 0;
}
