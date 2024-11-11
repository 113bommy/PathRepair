#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  n /= 1000;
  puts(n & 1 ? "1" : "3");
  return 0;
}
