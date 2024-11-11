#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N], sum[N], f[N], ans[N];
int n, r, c;
char ch[N * 6];
int main() {
  scanf("%d%d%d", &n, &r, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch + sum[i - 1] + 2);
    a[i] = strlen(ch + sum[i - 1] + 2);
    sum[i] = sum[i - 1] + 1 + a[i];
  }
  for (int i = 1; i <= n; i++)
    for (f[i] = max(f[i - 1], i); f[i] <= n && sum[f[i]] - sum[i - 1] - 1 <= c;
         f[i]++)
      ;
  f[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) ans[i] = i;
  for (; r; r >>= 1)
    for (int i = 1; i <= n; i++) {
      if (r & 1) ans[i] = f[ans[i]];
      f[i] = f[f[i]];
    }
  int pos = 1;
  for (int i = 2; i <= n; i++)
    if (ans[i] - i > ans[pos] - pos) pos = i;
  int last = 0;
  for (int i = pos; i <= ans[pos] - 1; i++) {
    if (last + a[i] > c) {
      last = 0;
      puts("");
    }
    if (last) putchar(' ');
    last += a[i] + 1;
    printf("%s", ch + sum[i - 1] + 2);
  }
  return 0;
}
