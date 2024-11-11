#include <bits/stdc++.h>
using namespace std;
const int maxn = 302000;
int n, x, d[maxn], sta[maxn], top;
long long minn[maxn], c[maxn], maxx[maxn];
void read() {
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) scanf("%d%I64d", &d[i], &c[i]), c[i] = x - c[i];
  for (int i = n; i >= 1; i--) d[i] -= d[i - 1];
}
void work() {
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, c[i]);
  for (int i = 1; i <= n; i++) c[i] = c[i - 1] + c[i];
  maxx[0] = 3e18;
  for (int i = 2; i <= n; i++) {
    long long now = 2e18;
    while (d[sta[top]] <= d[i] && top > 0) {
      now = min(minn[top], now);
      top--;
    }
    sta[++top] = i;
    minn[top] = min(now, c[i - 2]);
    maxx[top] = min(d[i] * d[i] + minn[top], maxx[top - 1]);
    ans = max(ans, c[i] - maxx[top]);
  }
  printf("%I64d\n", ans);
}
int main() {
  read();
  work();
  return 0;
}
