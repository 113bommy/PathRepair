#include <bits/stdc++.h>
using namespace std;
long long d[99][9];
void init() {
  d[0][0] = 1;
  for (int i = 1; i <= 18; i++) {
    d[i][0] = 1;
    d[i][1] = 9 + d[i - 1][1];
    d[i][2] = d[i - 1][2] + d[i - 1][1] * 9;
    d[i][3] = d[i - 1][3] + d[i - 1][2] * 9;
  }
}
int a[99];
long long calc(long long R) {
  if (R == 0) return 0;
  a[0] = 0;
  long long tem = R;
  while (tem) a[++a[0]] = tem % 10, tem /= 10;
  long long ret = 0;
  int num = 0;
  for (int i = a[0]; i >= 1; i--) {
    if (!a[i]) continue;
    if (num == 0)
      ret += (a[i] - 1) * (d[i - 1][2] + d[i - 1][1] + 1) + d[i - 1][3] +
             d[i - 1][2] + d[i - 1][1];
    if (num == 1)
      ret += (a[i] - 1) * (d[i - 1][1] + 1) + d[i - 1][2] + d[i - 1][1] + 1;
    if (num == 2) ret += a[i] + d[i - 1][1] + 1;
    ++num;
  }
  if (num < 3) ret++;
  return ret;
}
int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    long long L, R;
    scanf("%I64d%I64d", &L, &R);
    printf("%I64d\n", calc(R) - calc(L - 1));
  }
  return 0;
}
