#include <bits/stdc++.h>
const long long M = 1 << 20;
using namespace std;
long long sum[30][2], a[M], b[M], x, ans, Q, n, N;
long long read() {
  long long x = 0, f = 1, c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
void work(long long l, long long r, long long deep) {
  if (deep == 0) {
    sum[deep][0] = sum[deep][1] = 0;
    return;
  }
  long long mid = (l + r) >> 1;
  work(l, mid, deep - 1);
  work(mid + 1, r, deep - 1);
  for (int i = 1; i <= mid; i++)
    sum[deep][0] += lower_bound(a + mid + 1, a + r + 1, a[i]) - (a + mid + 1);
  for (int i = mid + 1; i <= r; i++)
    sum[deep][1] += lower_bound(a + l, a + mid + 1, a[i]) - (a + l);
  sort(a + l, a + r + 1);
}
int main() {
  n = read();
  N = 1 << n;
  for (long long i = 1; i <= N; i++) a[i] = read();
  work(1, N, n);
  Q = read();
  for (long long i = 1; i <= Q; i++) {
    x = read();
    ans = 0;
    for (long long i = x; x >= 0; x--) swap(sum[i][0], sum[i][1]);
    for (long long i = 0; i <= n; i++) ans += sum[i][0];
    printf("%I64d\n", ans);
  }
}
