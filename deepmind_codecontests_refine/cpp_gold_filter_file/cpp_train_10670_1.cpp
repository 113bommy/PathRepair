#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 100;
int num[maxn];
int cnt[50];
int n, k, x;
int main() {
  scanf("%d %d %d", &n, &k, &x);
  long long now = 1;
  for (int i = 0; i < k; ++i) now *= x;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &num[i]);
    for (int j = 0; j < 32; ++j)
      if (num[i] & (1 << j)) cnt[j]++;
  }
  long long Max = -1;
  for (int i = 1; i <= n; ++i) {
    long long t = 0;
    for (int j = 0; j < 32; ++j) {
      int c = cnt[j];
      if (num[i] & (1 << j)) c--;
      if (c) t |= (1 << j);
    }
    t |= (long long)now * num[i];
    Max = max(Max, t);
  }
  printf("%lld\n", Max);
  return 0;
}
