#include <bits/stdc++.h>
using namespace std;
long long k, b, n, t, p = 0, c = 1;
int main() {
  scanf("%I64d%I64d%I64d%I64d", &k, &b, &n, &t);
  for (p = 0; c <= t; p++) c = k * c + b;
  printf("%I64d", (n - p + 1 > 0 ? n - p + 1 : 0));
  return 0;
}
