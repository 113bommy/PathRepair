#include <bits/stdc++.h>
using namespace std;
long long N, M, suma, sumb, res, ans;
long long a[100010], b[100010];
void work() {
  res = 0;
  for (long long i = 1; i < N; i++) res += min(a[i], sumb);
  res += sumb;
  ans = min(res, ans);
}
int main() {
  scanf("%I64d%I64d", &N, &M);
  for (long long i = 1; i <= N; i++) scanf("%I64d", &a[i]), suma += a[i];
  for (long long i = 1; i <= M; i++) scanf("%I64d", &b[i]), sumb += b[i];
  sort(a + 1, a + N + 1);
  sort(b + 1, b + M + 1);
  ans = 2e18;
  work();
  for (long long i = 1; i <= max(N, M); i++) swap(a[i], b[i]);
  swap(N, M);
  swap(suma, sumb);
  work();
  printf("%I64d", ans);
}
