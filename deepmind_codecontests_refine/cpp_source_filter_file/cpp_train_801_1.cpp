#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 5;
int n, m;
long long d;
long long a[maxn], sum[maxn];
int main() {
  scanf("%d%d%lld", &n, &m, &d);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(&a[1], &a[n + 1]);
  int good = 1;
  sum[0] = 1;
  for (int i = 1, j = 1; i <= n; i++) {
    while (a[i] - a[j] > d) j++;
    good = sum[max(-1, i - m)] - sum[j - 2];
    sum[i] = sum[i - 1];
    if (good >= 1) sum[i]++;
  }
  if (good)
    printf("YES");
  else
    printf("NO");
}
