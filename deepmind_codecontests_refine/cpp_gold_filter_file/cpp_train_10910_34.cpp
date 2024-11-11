#include <bits/stdc++.h>
int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  printf("%d", std::min(n*a, b));
}