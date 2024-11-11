#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("%d", (a xor b) & (c xor d) xor (b & c) | (a xor d));
  return 0;
}
