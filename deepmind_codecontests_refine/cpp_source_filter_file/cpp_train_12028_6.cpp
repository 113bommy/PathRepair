#include <bits/stdc++.h>
const long long N = 200010;
const long long Inf = 1e16;
using namespace std;
queue<long long> qu[5];
long long a[N];
long long i, j, k, l, n, m, B, C, ans, ansx, x, p, o, vis[10], dx, u, prex;
long long cal(long long x) {
  if (x < 0) printf("asdf");
  return ((x / 5) * B + (x % 5) * C);
}
void out(long long x) {
  long long maxy = -1, y = -1;
  for (long long i = 0; i < 5; i++)
    if ((!qu[i].empty()) && cal(x - qu[i].front()) > maxy)
      maxy = cal(x - qu[i].front()), y = i;
  qu[y].pop();
  ansx -= maxy;
}
int main() {
  scanf("%I64d%I64d%I64d%I64d", &n, &k, &B, &C);
  B = min(B, 5 * C);
  long long ma = -Inf;
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a + 1, a + 1 + n);
  ans = Inf;
  for (o = 0; o < 5; o++) {
    for (i = 0; i < 5; i++)
      while (!qu[i].empty()) qu[i].pop();
    for (u = 0; u < 5; u++)
      if (((a[1] + u) % 5 + 5) % 5 == o) {
        x = a[1] + u;
        break;
      }
    qu[((a[1] % 5) + 5) % 5].push(a[1]);
    p = 1;
    ansx = u * C;
    prex = x;
    if (p == k && ansx < ans) ans = ansx;
    for (j = 2; j <= n; j++) {
      for (u = 0; u < 5; u++)
        if (((a[j] + u) % 5 + 5) % 5 == o) {
          x = a[j] + u;
          break;
        }
      qu[((a[j] % 5) + 5) % 5].push(a[j]);
      ansx += u * C + p * B * ((x - prex) / 5);
      p++;
      prex = x;
      if (p > k) out(x), p--;
      if (p == k && ansx < ans) ans = ansx;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
