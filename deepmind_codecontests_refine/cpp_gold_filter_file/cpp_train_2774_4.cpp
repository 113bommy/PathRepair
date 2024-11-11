#include <bits/stdc++.h>
using namespace std;
int k;
long long n;
long long f[100007];
int main() {
  scanf("%I64d%d", &n, &k);
  int keep = 1;
  long long num = 0, cnt = 0;
  for (int i = 1; i <= k; i++) {
    scanf("%I64d", &f[i]);
    long long nu = n / f[i];
    long long cn = nu * f[i];
    if (cn > cnt) {
      keep = i;
      num = nu;
      cnt = cn;
    }
  }
  printf("%d %I64d", keep, num);
  return 0;
}
