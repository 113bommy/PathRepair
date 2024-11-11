#include <bits/stdc++.h>
int main() {
  int a;
  scanf("%d", &a);
  a -= 43500;
  puts(a > 0 ? (a > 2000 ? "3" : "2") : "1");
  return 0;
}
