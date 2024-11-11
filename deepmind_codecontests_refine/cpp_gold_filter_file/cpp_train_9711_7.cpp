#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const int e[6] = {3, 30, 300, 3000, 30000, 300000};
int m, i, j, k, f[6];
int qx[1000005], ql, qr;
long long dp[1000005], qy[1000005];
int main() {
  read(m);
  m--;
  for (((i)) = (0); ((i)) <= (((int)(6)) - 1); ((i))++) read(f[i]);
  for (((i)) = (0); ((i)) <= (((int)(1000000)) - 1); ((i))++) {
    int t = i;
    for (((j)) = (0); ((j)) <= (((int)(6)) - 1); ((j))++) {
      if ((t % 10) % 3 == 0) {
        dp[i] += 1ll * ((t % 10) / 3) * f[j];
      }
      t /= 10;
    }
  }
  for (((i)) = (0); ((i)) <= (((int)(6)) - 1); ((i))++) {
    for (j = 0; j < e[i]; j++) {
      ql = 1;
      qr = 0;
      for (k = j; k < 1000000; k += e[i]) {
        while (ql <= qr && qx[ql] < k - m * 3ll * e[i]) ql++;
        while (ql <= qr && qy[qr] <= dp[k] - 1ll * f[i] * (k / e[i])) qr--;
        qx[++qr] = k;
        qy[qr] = dp[k] - 1ll * f[i] * (k / e[i]);
        dp[k] = qy[ql] + 1ll * f[i] * (k / e[i]);
      }
    }
  }
  int q;
  read(q);
  while (q--) {
    int x;
    read(x);
    printf("%lld\n", dp[x]);
  }
  return 0;
}
