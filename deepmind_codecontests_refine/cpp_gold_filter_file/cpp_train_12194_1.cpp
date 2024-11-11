#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 7005;
int mu[M], Q;
bitset<M> a[N], b1[M], b2[M];
int main() {
  for (int i = (int)(1); i <= (int)(M - 1); i++) mu[i] = 1;
  for (int i = (int)(2); i <= (int)(M - 1); i++)
    for (int j = (int)(1); j <= (int)((M - 1) / i / i); j++) mu[i * i * j] = 0;
  for (int i = (int)(1); i <= (int)(M - 1); i++)
    for (int j = (int)(1); j <= (int)((M - 1) / i); j++) b1[i * j][i] = 1;
  for (int i = (int)(1); i <= (int)(M - 1); i++)
    for (int j = (int)(1); j <= (int)((M - 1) / i); j++) b2[i][i * j] = mu[j];
  scanf("%*d%d", &Q);
  while (Q--) {
    int tp, x, y, z;
    scanf("%d%d%d", &tp, &x, &y);
    if (tp == 1) a[x] = b1[y];
    if (tp == 2) scanf("%d", &z), a[x] = a[y] ^ a[z];
    if (tp == 3) scanf("%d", &z), a[x] = a[y] & a[z];
    if (tp == 4) putchar('0' + (a[x] & b2[y]).count() % 2);
  }
}
