#include <bits/stdc++.h>
using namespace std;
const int M = 300000;
long long c[2][M + 10], ans;
int n;
void add(long long c[], int x, int y) {
  for (; x <= M; x += x & (-x)) c[x] += y;
}
long long get(long long c[], int x) {
  long long s = 0;
  for (; x; x -= x & (-x)) s += c[x];
  return s;
}
int main() {
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    ans += 1ll * (i - 1) * x - get(c[0], x);
    ans += sum;
    for (int j = 1; j <= M / x; j++) ans += get(c[1], j * x - 1) * x;
    ans -= (i - 1) * x * (M / x);
    add(c[1], x, 1);
    sum += x;
    for (int j = x; j <= M; j += x) add(c[0], j, x);
    printf("%lld%c", ans, " \n"[i == n]);
  }
  return 0;
}
