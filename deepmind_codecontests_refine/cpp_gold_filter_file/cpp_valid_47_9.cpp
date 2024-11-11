#include <bits/stdc++.h>
using namespace std;
long long num[500005];
void solve(int x) {
  long long a, o;
  printf("and 1 %d\n", x);
  fflush(stdout);
  scanf("%lld", &a);
  printf("or 1 %d\n", x);
  fflush(stdout);
  scanf("%lld", &o);
  long long wei[40];
  for (int i = 1; i <= 34; ++i) {
    if (a & (1ll << (i - 1)))
      wei[i] = 1;
    else if (o & (1ll << (i - 1))) {
      if (num[1] & (1ll << (i - 1)))
        wei[i] = 0;
      else
        wei[i] = 1;
    } else
      wei[i] = 0;
  }
  long long now = 0;
  for (int i = 1; i <= 34; ++i) {
    now += wei[i] << (i - 1);
  }
  num[x] = now;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  long long a12, o12, a13, o13, a23, o23;
  printf("and 1 2\n");
  fflush(stdout);
  scanf("%lld", &a12);
  printf("or 1 2\n");
  fflush(stdout);
  scanf("%lld", &o12);
  printf("and 1 3\n");
  fflush(stdout);
  scanf("%lld", &a13);
  printf("or 1 3\n");
  fflush(stdout);
  scanf("%lld", &o13);
  printf("and 2 3\n");
  fflush(stdout);
  scanf("%lld", &a23);
  printf("or 2 3\n");
  fflush(stdout);
  scanf("%lld", &o23);
  long long a[5][40];
  for (int i = 1; i <= 34; ++i) a[1][i] = a[2][i] = a[3][i] = -1;
  for (int i = 1; i <= 34; ++i) {
    if (a12 & 1ll << (i - 1)) a[1][i] = 1, a[2][i] = 1;
    if (a23 & 1ll << (i - 1)) a[2][i] = 1, a[3][i] = 1;
    if (a13 & 1ll << (i - 1)) a[1][i] = 1, a[3][i] = 1;
    if ((o12 & 1ll << (i - 1)) == 0) a[1][i] = a[2][i] = 0;
    if ((o23 & 1ll << (i - 1)) == 0) a[2][i] = a[3][i] = 0;
    if ((o13 & 1ll << (i - 1)) == 0) a[1][i] = a[3][i] = 0;
  }
  for (int i = 1; i <= 34; ++i) {
    if (a[1][i] == -1) {
      if (a[2][i] == 0)
        a[1][i] = 1;
      else
        a[1][i] = 0;
    } else if (a[2][i] == -1) {
      if (a[1][i] == 0)
        a[2][i] = 1;
      else
        a[2][i] = 0;
    } else if (a[3][i] == -1) {
      if (a[2][i] == 0)
        a[3][i] = 1;
      else
        a[3][i] = 0;
      if (a[1][i] == 0)
        a[3][i] = 1;
      else
        a[3][i] = 0;
    }
    if (a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[3][i] == -1)
      a[1][i] = a[2][i] = a[3][i] = 0;
  }
  for (int i = 1; i <= 34; ++i) {
    for (int j = 1; j <= 3; ++j) num[j] += a[j][i] << (long long)(i - 1);
  }
  for (int i = 4; i <= n; ++i) {
    solve(i);
  }
  sort(num + 1, num + n + 1);
  printf("finish %lld", num[k]);
  fflush(stdout);
}
