#include <bits/stdc++.h>
int main() {
  long long int n, b, c;
  printf("");
  scanf("%lli", &n);
  printf("");
  scanf("%lli", &b);
  printf("");
  scanf("%lli", &c);
  if (n % 2 == 0) {
    if (b + c <= n + 1) {
      printf("white");
    } else {
      printf("black");
    }
  } else {
    if (b + c <= n + 1) {
      printf("white");
    } else {
      printf("black");
    }
  }
  return 0;
}
