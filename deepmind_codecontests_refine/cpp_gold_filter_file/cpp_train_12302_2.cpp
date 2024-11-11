#include <bits/stdc++.h>
using namespace std;
const int N = 200010, mo = 1e9 + 7;
int n, L[N], R[N], pre[N], suf[N], a[10], ans, sum[N];
char c;
int read() {
  int x = 0, sig = 1;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') sig = -sig;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  return x * sig;
}
int quick(int x, int y) {
  int s = 1;
  for (int i = 1; i <= y; i <<= 1, x = 1ll * x * x % mo)
    if (i & y) s = 1ll * s * x % mo;
  return s;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) L[i] = read();
  for (int i = 1; i <= n; i++) R[i] = read();
  pre[0] = suf[n + 1] = 1;
  for (int i = 1; i <= n; i++)
    pre[i] = 1ll * pre[i - 1] * (R[i] - L[i] + 1) % mo;
  for (int i = n; i; i--) suf[i] = 1ll * suf[i + 1] * (R[i] - L[i] + 1) % mo;
  ans = suf[1];
  sum[1] = R[1] - L[1] + 1;
  for (int i = 2; i <= n; i++) {
    int t = (1ll * (R[i] - L[i] + 1) * (R[i - 1] - L[i - 1] + 1) -
             max(0, min(R[i], R[i - 1]) - max(L[i], L[i - 1]) + 1)) %
            mo;
    ans = (ans + 1ll * pre[i - 2] * suf[i + 1] % mo * t) % mo;
    sum[i] = (1ll * sum[i - 1] * (R[i] - L[i] + 1) + 1ll * pre[i - 2] * t) % mo;
    ans = (ans + 2ll * sum[i - 2] * t % mo * suf[i + 1]) % mo;
    if (i == 2) {
      ans = (ans + 2ll * suf[3] * t) % mo;
      continue;
    }
    a[0] = L[i - 2];
    a[1] = R[i - 2] + 1;
    a[2] = L[i - 1];
    a[3] = R[i - 1] + 1;
    a[4] = L[i];
    a[5] = R[i] + 1;
    sort(a, a + 6);
    int s = 0;
    for (int x = 0; x < 5; x++)
      if (a[x] < a[x + 1] && L[i - 2] <= a[x] && R[i - 2] >= a[x]) {
        for (int y = 0; y < 5; y++)
          if (a[y] < a[y + 1] && L[i - 1] <= a[y] && R[i - 1] >= a[y]) {
            for (int z = 0; z < 5; z++)
              if (a[z] < a[z + 1] && L[i] <= a[z] && R[i] >= a[z]) {
                if (x != y && y != z)
                  s = (s + 1ll * (a[x + 1] - a[x]) * (a[y + 1] - a[y]) % mo *
                               (a[z + 1] - a[z])) %
                      mo;
                else if (x == y && y != z)
                  s = (s + 1ll * (a[x + 1] - a[x]) * (a[y + 1] - a[y] - 1) %
                               mo * (a[z + 1] - a[z])) %
                      mo;
                else if (x != y && y == z)
                  s = (s + 1ll * (a[x + 1] - a[x]) * (a[y + 1] - a[y]) % mo *
                               (a[z + 1] - a[z] - 1)) %
                      mo;
                else
                  s = (s + 1ll * (a[x + 1] - a[x] - 1) * (a[y + 1] - a[y]) %
                               mo * (a[z + 1] - a[z] - 1)) %
                      mo;
              }
          }
      }
    ans = (ans + 2ll * s * pre[i - 3] % mo * suf[i + 1]) % mo;
  }
  for (int i = 1; i <= n; i++)
    ans = 1ll * ans * quick(R[i] - L[i] + 1, mo - 2) % mo;
  printf("%d\n", ans);
  return 0;
}
