#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e6 + 2;
const double PI = acos(-1);
const int INF = 2e9;
int p[MAXN], d[MAXN], cnt[MAXN], t, i, a, b;
long long j;
int main() {
  for (i = 2; i < MAXN; i++)
    if (!d[i]) {
      d[i] = 0;
      for (j = i * 1ll * i; j < MAXN; j += i) d[j] = i;
    }
  for (i = 2; i < 1e4; i++)
    if (!d[i])
      cnt[i] = 1;
    else
      cnt[i] = cnt[i / d[i]] + 1;
  for (i = 1; i < MAXN; i++) p[i] = p[i - 1] + cnt[i];
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d%d", &a, &b);
    printf("%d\n", p[a] - p[b]);
  }
  return 0;
}
