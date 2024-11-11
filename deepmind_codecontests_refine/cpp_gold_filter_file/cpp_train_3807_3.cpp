#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) { return x > y; }
bool prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  if (n > 2 && n % 2 == 0) {
    printf("2\n");
  } else if (n == 2) {
    printf("1\n");
  } else {
    if (prime(n))
      printf("1\n");
    else if (prime(n - 2))
      printf("2\n");
    else
      printf("3\n");
  }
  return 0;
}
