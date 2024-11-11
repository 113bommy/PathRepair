#include <bits/stdc++.h>
using namespace std;
int a[2050000];
pair<int, int> b[205000];
long long f[30];
long long af[30];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 1 << n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    int l = 1 << i;
    for (int j = 0; j < 1 << (n - i - 1); j++) {
      for (int k = 1; k <= l; k++) b[k] = make_pair(a[2 * j * l + k], 1);
      for (int k = l + 1; k <= 2 * l; k++)
        b[k] = make_pair(a[2 * j * l + k], 2);
      sort(b + 1, b + 1 + 2 * l);
      b[2 * l + 1] = make_pair(-1, 0);
      long long p = 0, q = 0;
      long long tp = 0, tq = 0;
      for (int k = 1; k <= 2 * l; k++) {
        if (b[k].second == 1)
          tp++;
        else
          tq++;
        if (b[k].first != b[k + 1].first) {
          f[i] += p * tq;
          af[i] += q * tp;
          p += tp, q += tq;
          tp = tq = 0;
        }
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int u;
    scanf("%d", &u);
    for (int i = u - 1; i >= 0; i--) swap(f[i], af[i]);
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += af[i];
    printf("%lld\n", sum);
  }
}
