#include <bits/stdc++.h>
using namespace std;
long long n, i, j, x, a[100010], b[100010], c[100010];
vector<long long> zh;
int main() {
  scanf("%lld", &n);
  j = 1;
  for (i = 1; i <= n; i++) {
    while (__builtin_popcount(j) != 6) j++;
    a[i] = j++;
  }
  for (j = 0; j < 13; j++) {
    zh.clear();
    for (i = 1; i <= n; i++)
      if (a[i] & (1ll << j)) zh.push_back(i);
    x = zh.size();
    if (!x) {
      b[j] = 0;
      continue;
    }
    printf("? %lld ", x);
    for (i = 0; i < x; i++) printf("%lld ", zh[i]);
    puts("");
    fflush(stdout);
    scanf("%lld", &b[j]);
  }
  for (j = 0; j < 63; j++) {
    x = 0;
    for (i = 0; i < 13; i++)
      if (b[i] & (1ll << j)) x |= (1ll << i);
    if (!x) continue;
    if (__builtin_popcount(x) > 6) {
      for (i = 1; i <= n; i++) c[i] |= (1ll << j);
    } else {
      for (i = 1; i <= n; i++)
        if (a[i] != x) c[i] |= (1ll << j);
    }
  }
  printf("! ");
  for (i = 1; i <= n; i++) printf("%lld ", c[i]);
  puts("");
}
