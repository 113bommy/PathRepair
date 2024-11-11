#include <bits/stdc++.h>
using namespace std;
const int a1[8] = {-2, -2, -1, -1, 1, 1, 2, 2},
          a2[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
struct ww {
  int x, y;
} g[2010 * 2010];
int i, j, k, n, m, l, r, x, y;
int f[2010][2010];
int an[2010], a[2010];
long long K;
int main() {
  scanf("%I64d%d", &K, &n);
  memset(f, 255, sizeof(f));
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    f[x + 1000][y + 1000] = 0;
  }
  l = r = 1;
  f[1000][1000] = 0;
  g[1] = (ww){1000, 1000};
  for (; l <= r; l++) {
    ww A = g[l];
    int B = f[A.x][A.y];
    an[B]++;
    if (B == 500) continue;
    for (i = 0; i <= 7; i++) {
      int x = A.x + a1[i], y = A.y + a2[i];
      if (f[x][y] < 0) {
        f[x][y] = B + 1;
        g[++r] = (ww){x, y};
      }
    }
  }
  if (K <= 500) {
    int ans = 0;
    for (i = 0; i <= K; i++) ans += an[i];
    printf("%d\n", ans);
  } else {
    int A = an[500] - an[499];
    int ans = 0;
    for (i = 0; i <= 499; i++) ans += an[i];
    K -= 499;
    long long B = K % 1000000007 * x % 1000000007;
    long long C = K, D = K - 1;
    if (C & 1)
      D /= 2;
    else
      C /= 2;
    ans = ((C % 1000000007) * (D % 1000000007) % 1000000007 * A + B + ans) %
          1000000007;
    printf("%d\n", ans);
  }
  return 0;
}
