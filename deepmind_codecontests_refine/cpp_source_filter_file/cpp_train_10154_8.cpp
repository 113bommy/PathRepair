#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500001;
const int MAXB = 60;
bitset<MAXN> x[MAXB];
int main() {
  int n;
  scanf("%d", &n);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    s ^= a, b ^= a;
    for (int j = 0; j < 60; j++) x[j][i] = (b >> j & 1);
  }
  for (int j = 0; j < 60; j++) x[j][n] = (s >> j & 1);
  for (int i = 0, j = 0; i < n && j < 60; i++) {
    int mx = j;
    for (int k = j; k < 60; k++)
      if (x[k][i]) mx = k;
    if (!x[j][i]) continue;
    swap(x[j], x[mx]);
    for (int k = j + 1; k < 60; k++)
      if (x[k][i]) x[k] ^= x[j];
    j++;
  }
  int t = 60;
  for (int j = 0; j < 60; j++) {
    bool has = 0;
    for (int i = 0; i < n; i++) has |= x[j][i];
    if (!has) {
      if (x[j][n])
        return 0 * printf("1/1");
      else
        t--;
    }
  }
  printf("%lld/%lld", (1LL << t) - 1, (1LL << t));
  return 0;
}
