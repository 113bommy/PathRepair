#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  int num1 = n - 1;
  if (n == 1) {
    printf("1 1\n");
    printf("%lld\n", a[1] * -1);
    printf("1 1\n");
    printf("0\n");
    printf("1 1\n");
    printf("0\n");
    return 0;
  }
  printf("1 %d\n", num1);
  for (int i = 1; i <= num1; i++) {
    if (i != 1) printf(" ");
    printf("%lld", a[i] * num1);
    a[i] = a[i] + a[i] * num1;
  }
  printf("\n");
  printf("2 %d\n", n);
  for (int i = 2; i <= n; i++) {
    if (i != 2) printf(" ");
    if (i != n)
      printf("0");
    else {
      printf("%lld", a[i] * (n - 1));
      a[i] = a[i] + a[i] * (n - 1);
    }
  }
  printf("\n");
  printf("1 %d\n", n);
  for (int i = 1; i <= n; i++) {
    if (i != 1) printf(" ");
    printf("%lld", a[i] * -1);
  }
  return 0;
}
