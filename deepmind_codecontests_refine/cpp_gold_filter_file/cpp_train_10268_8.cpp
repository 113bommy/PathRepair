#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5;
int a[maxn], b[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]), b[i] += a[i];
  for (int i = 0; i < n - 1; i++)
    if (b[i + 1] > b[i]) b[i + 1] = b[i] + 1;
  for (int i = n - 2; i >= 0; i--)
    if (b[i] > b[i + 1]) b[i] = b[i + 1] + 1;
  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > b[i]) {
      return puts("-1");
    } else {
      ans += b[i] - a[i];
    }
  printf("%I64d\n", ans);
  for (int i = 0; i < n; i++) printf("%d ", b[i]);
  return 0;
}
