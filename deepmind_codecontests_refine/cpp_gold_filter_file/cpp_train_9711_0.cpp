#include <bits/stdc++.h>
using namespace std;
const int tab[] = {1, 10, 100, 1000, 10000, 100000};
long long f[1000005];
int k, v[15];
void insert(int v, int c) {
  v *= 3;
  int e = 3 * (k - 1);
  for (int i = (int)(0); i <= (int)(22); i++) {
    int s = min(1 << i, e);
    e -= s;
    long long V = 1ll * v * s, C = 1ll * c * s;
    if (V <= 999999)
      for (int j = (int)(999999); j >= (int)(V); j--)
        f[j] = max(f[j], f[j - V] + C);
  }
}
int main() {
  scanf("%d", &k);
  for (int i = (int)(0); i <= (int)(5); i++) scanf("%d", &v[i]);
  for (int i = (int)(0); i <= (int)(5); i++)
    for (int j = (int)(0); j <= (int)(999999); j++)
      if (j / tab[i] % 10 % 3 == 0) f[j] += 1ll * (j / tab[i] % 10 / 3) * v[i];
  for (int i = (int)(0); i <= (int)(5); i++) insert(tab[i], v[i]);
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", f[x]);
  }
}
