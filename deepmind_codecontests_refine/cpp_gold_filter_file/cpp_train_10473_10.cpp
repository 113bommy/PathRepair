#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int w = 0, p, m, b;
  scanf("%I64d%I64d", &m, &b);
  for (long long int i = 0; i <= m * b; i++) {
    p = b - (i / m);
    if (i % m > 0) p--;
    w = max(w, (p + 1) * ((i * (i + 1)) / 2) + (i + 1) * ((p * (p + 1)) / 2));
  }
  printf("%I64d", w);
  return 0;
}
