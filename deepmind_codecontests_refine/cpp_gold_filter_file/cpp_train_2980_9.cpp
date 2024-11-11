#include <bits/stdc++.h>
using namespace std;
long long int k, n, m, an1, an2, a, b;
int alice[5][5], bob[5][5], res[5][5], lef, ri, tmp[20], tpp[20];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  scanf("%lld%lld%lld", &k, &a, &b);
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) scanf("%d", &alice[i][j]);
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) scanf("%d", &bob[i][j]);
  tmp[0] = 0, tpp[0] = 0;
  for (int i = 1, x, y; i <= k; i++) {
    if (a == b) x = 0, y = 0;
    if (res[a][b]) {
      lef = res[a][b];
      ri = i - 1;
      break;
    } else
      res[a][b] = i;
    if (a == 1 && b == 2)
      x = 0, y = 1;
    else if (a == 2 && b == 1)
      x = 1, y = 0;
    else if (a == 2 && b == 3)
      x = 0, y = 1;
    else if (a == 3 && b == 2)
      x = 1, y = 0;
    else if (a == 3 && b == 1)
      x = 0, y = 1;
    else if (a == 1 && b == 3)
      x = 1, y = 0;
    tmp[i] = tmp[i - 1] + x;
    tpp[i] = tpp[i - 1] + y;
    x = alice[a][b], y = bob[a][b];
    a = x, b = y;
  }
  if (k < lef || lef == 0) {
    printf("%lld %lld\n", (long long int)tmp[k], (long long int)tpp[k]);
    return 0;
  }
  an1 = tmp[lef - 1], an2 = tpp[lef - 1];
  a = tmp[ri] - tmp[lef - 1], b = tpp[ri] - tpp[lef - 1];
  k -= (lef - 1);
  m = ri - lef + 1;
  n = (k / m);
  an1 += (a * n);
  an2 += (b * n);
  n = (k % m);
  an1 += (tmp[lef - 1 + n] - tmp[lef - 1]);
  an2 += (tpp[lef - 1 + n] - tpp[lef - 1]);
  printf("%lld %lld\n", an1, an2);
  return 0;
}
