#include <bits/stdc++.h>
int n;
int num[10001];
bool isprime(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 4;; i++) {
    if ((!isprime(i)) && (!isprime(i + n))) {
      printf("%d %d\n", i + n, i);
      break;
    }
  }
  return 0;
}
