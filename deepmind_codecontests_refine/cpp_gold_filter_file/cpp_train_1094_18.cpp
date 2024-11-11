#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6, L = 18;
int a[MAXN], N;
long long p[MAXN];
pair<int, int> r(0, 1);
int ok(double x) {
  for (int i = 1; i <= N; i++) {
    int n = 0;
    for (int l = L; l >= 0; l--) {
      int m = n + (1 << l);
      if (i - m > 0 && N + 1 - m > i &&
          a[i - m] + a[N + 1 - m] - 2 * (a[i] + x) >= 0)
        n = m;
    }
    if (p[i] - p[i - n - 1] + p[N] - p[N - n] - (2 * n + 1) * (x + a[i]) >= 0) {
      r = {n, i};
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
  sort(a + 1, a + N + 1);
  for (int i = 1; i <= N; i++) p[i] = p[i - 1] + a[i];
  double lo = 0, hi = MAXN;
  for (int n = 0; n < 100; n++) {
    double mi = (lo + hi) / 2;
    if (ok(mi))
      lo = mi;
    else
      hi = mi;
  }
  printf("%d\n", 2 * r.first + 1);
  for (int i = r.second - r.first; i <= r.second; i++) printf("%d ", a[i]);
  for (int i = N - r.first + 1; i <= N; i++) printf("%d ", a[i]);
}
