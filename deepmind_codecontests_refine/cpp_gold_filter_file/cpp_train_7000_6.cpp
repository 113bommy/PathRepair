#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
long long a[maxn], mi[maxn];
int n;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= (n - 1) / 2 + 1; i++) scanf("%lld", &a[i]);
  long long x;
  scanf("%lld", &x);
  long long now = 0;
  mi[1] = 0;
  for (int i = 2; i <= (n - 1) / 2 + 2; i++) {
    now += x - a[i - 1];
    mi[i] = min(mi[i - 1], now);
  }
  now = 0;
  for (int i = 1; i <= (n - 1) / 2 + 1; i++) now += a[i];
  for (int i = (n - 1) / 2 + 1; i <= n; i++) {
    if (now + mi[n - i + 1] > 0) {
      printf("%d\n", i);
      return 0;
    }
    now += x;
  }
  printf("-1\n");
  return 0;
}
