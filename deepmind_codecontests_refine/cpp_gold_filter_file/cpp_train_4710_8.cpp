#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL mat[3][4] = {
    {0, 1, 2, 3},
    {0, 2, 3, 1},
    {0, 3, 1, 2},
};
LL recalc(LL n, int typ) {
  LL ans = 0;
  for (int i = 0; i <= 31; i++) {
    if ((n & (1ll << i + i)) || (n & (1ll << i + i + 1))) {
      ans |= (mat[typ][(n >> i + i) & 3] << i + i);
    }
  }
  return ans;
}
LL calc(LL n, int typ) {
  LL m = 1;
  int len = 2;
  while (n > m) {
    n -= m;
    len += 2;
    m <<= 2;
  }
  LL ans = recalc(n - 1, typ);
  if (typ != 1) {
    ans |= 1ll << len - 2;
  }
  if (typ != 0) {
    ans |= 1ll << len - 1;
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    LL n;
    scanf("%I64d", &n);
    LL f = (n + 2) / 3;
    int typ = (n - 1) % 3;
    printf("%I64d\n", calc(f, typ));
  }
  return 0;
}
