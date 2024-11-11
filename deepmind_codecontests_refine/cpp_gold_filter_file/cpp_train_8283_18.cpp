#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("%d\n", ((a ^ b) & (c | d)) ^ ((b & c) | (a ^ d)));
  return 0;
}
