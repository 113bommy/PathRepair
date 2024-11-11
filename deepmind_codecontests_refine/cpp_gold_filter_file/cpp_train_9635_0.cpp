#include <bits/stdc++.h>
using namespace std;
int a[100010], b, n, i, j, la[100010], fi[100010];
long long ans1, ans2, now1, now2;
int main() {
  scanf("%d%d", &n, &b);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), la[i] = i + 1, fi[i] = i - 1;
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= n; i++)
    if (a[i] > b) break;
  if (n < 2) {
    puts("0");
    return 0;
  }
  if (n == 2) {
    printf("%d", min(abs(b - a[1]), abs(b - a[2])));
    return 0;
  }
  if (i >= n)
    ans1 = b - a[1];
  else if (i < 2)
    ans1 = a[n - 1] - b;
  else
    ans1 = min((abs(b - a[1]) << 1) + abs(a[n - 1] - b),
               abs(b - a[1]) + (abs(a[n - 1] - b) << 1));
  if (i > n)
    ans2 = b - a[2];
  else if (i > 2)
    ans2 = min((abs(b - a[2]) << 1) + abs(a[n] - b),
               abs(b - a[2]) + (abs(a[n] - b) << 1));
  else
    ans2 = a[n] - b;
  printf("%I64d", min(ans1, ans2));
  return 0;
}
