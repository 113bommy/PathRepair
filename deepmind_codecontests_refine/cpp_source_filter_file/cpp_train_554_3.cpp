#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  n -= 43500;
  puts(n > 0 ? (n > 200 ? "3" : "2") : "1");
  return 0;
}
