#include <bits/stdc++.h>
using namespace std;
const int N = 7005;
int n, q, mu[N], pri[N], tot;
bool notp[N];
bitset<N> a[100007], G[N], Mu[N];
inline void init() {
  notp[0] = notp[1] = true;
  mu[1] = 1;
  for (register int i = 2; i <= N - 5; i++) {
    if (!notp[i]) {
      pri[tot++] = i;
      mu[i] = -1;
    }
    for (register int j = 0; j < tot && i * pri[j] <= N - 5; j++) {
      notp[i * pri[j]] = true;
      if (i % pri[j])
        mu[i * pri[j]] = -mu[i];
      else {
        mu[i * pri[j]] = 0;
        break;
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &q);
  init();
  for (register int i = 1; i <= 7000; i++)
    for (register int j = i; j <= 7000; j += i) {
      G[j][i] = 1;
      Mu[i][j] = mu[j / i] != 0;
    }
  while (q--) {
    int opt, x, y, z;
    scanf("%d%d%d", &opt, &x, &y);
    switch (opt) {
      case 1:
        a[x] = G[y];
        break;
      case 2:
        scanf("%d", &z);
        a[x] = a[y] ^ a[z];
        break;
      case 3:
        scanf("%d", &z);
        a[x] = a[y] & a[z];
        break;
      case 4:
        putchar(((a[x] & Mu[y]).count() & 1) + '0');
    }
  }
}
