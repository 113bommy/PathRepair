#include <bits/stdc++.h>
using namespace std;
int fib[1000];
int fibgen(int n) {
  fib[0] = 0;
  fib[1] = 1;
  int i = 1;
  while (fib[i] < n) {
    i++;
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return i;
}
int main(void) {
  int n;
  scanf("%d", &n);
  if (n == 0)
    printf("0 0 0\n");
  else if (n == 1)
    printf("0 0 1\n");
  else if (n == 2)
    printf("0 1 1\n");
  else if (n == 3)
    printf("0 1 2\n");
  else {
    int pos = fibgen(n);
    printf("%d %d %d", fib[pos - 1], fib[pos - 3], fib[pos - 4]);
  }
  return 0;
}
