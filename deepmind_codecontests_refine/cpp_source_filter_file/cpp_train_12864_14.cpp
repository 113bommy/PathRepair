#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000, L = 1440;
int t[maxn], n, cur1, cur2;
long long f[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  cur1 = 1;
  cur2 = 1;
  for (int i = 1; i <= n; i++) {
    while (cur1 < i && t[i] - t[cur1] > 90) cur1++;
    while (cur2 < i && t[i] - t[cur2] > 1440) cur2++;
    f[i] = min(f[i - 1] + 20, min(f[cur1 - 1] + 50, f[cur2 - 1] + 120));
    printf("%I64d\n", f[i] - f[i - 1]);
  }
  return 0;
}
