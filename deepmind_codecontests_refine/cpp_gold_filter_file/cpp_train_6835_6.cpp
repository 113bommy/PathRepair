#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
long long a[70], b[70];
int get(long long x) {
  int m = -1;
  while (x) {
    m++;
    x >>= 1;
  }
  return m;
}
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < 62; i++) {
    b[i] = 1ll << i;
  }
  while (q--) {
    long long x, k;
    int f;
    scanf("%d", &f);
    if (f == 1) {
      scanf("%I64d%I64d", &x, &k);
      int pos = get(x);
      k = (k % b[pos] + b[pos]) % b[pos];
      a[pos] = (a[pos] + k + b[pos]) % b[pos];
    } else if (f == 2) {
      scanf("%I64d%I64d", &x, &k);
      int pos = get(x);
      k = (k % b[pos] + b[pos]) % b[pos];
      for (int i = pos; i < 62; i++) {
        a[i] = (a[i] + k + b[i]) % b[i];
        k = k * 2;
      }
    } else {
      scanf("%I64d", &x);
      printf("%I64d", x);
      long long pos = get(x);
      int te = pos;
      pos = (x - b[pos] + a[pos]) % b[pos];
      for (int i = te - 1; i >= 0; i--) {
        pos = pos / 2;
        printf(" %I64d", (pos - a[i] + b[i]) % b[i] + b[i]);
      }
      puts("");
    }
  }
}
