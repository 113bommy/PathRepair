#include <bits/stdc++.h>
int main() {
  int t;
  long long int n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    int count;
    count = (n + 1) / 10;
    printf("%d\n", count);
  }
}
