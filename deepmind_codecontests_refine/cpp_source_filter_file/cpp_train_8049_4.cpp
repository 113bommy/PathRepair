#include <bits/stdc++.h>
using namespace std;
int fac[1000];
int num;
int a[20010];
int n;
void getf(int x) {
  int i;
  for (i = 1; i <= x; i++)
    if (x % i == 0 && x / i >= 3) fac[num++] = i;
}
int com(int st, int k) {
  int s = 0;
  int i;
  for (i = st; i <= n; i += k) s += a[i];
  return s;
}
int main() {
  int i, j;
  scanf("%d", &n);
  {
    num = 0;
    getf(n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    int mx = 0;
    for (i = 0; i < num; i++)
      for (j = 1; j <= fac[i]; j++) mx = max(mx, com(j, fac[i]));
    printf("%d\n", mx);
  }
  return 0;
}
