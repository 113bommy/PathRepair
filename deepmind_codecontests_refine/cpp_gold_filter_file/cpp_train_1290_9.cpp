#include <bits/stdc++.h>
using namespace std;
const int INF = (0u - 1) / 2;
int main() {
  long long a, b, m;
  long long out = 0;
  scanf("%I64d %I64d %I64d", &a, &b, &m);
  if (a <= 0 && b <= 0) {
    if (m > a && m > b)
      printf("-1\n");
    else
      printf("0\n");
    return 0;
  }
  if (b < a) swap(a, b);
  if (m <= b) {
    printf("0\n");
    return 0;
  }
  if (a < 0) {
    out += (-a / b) + 1;
    a += b * out;
  }
  if (b < a) swap(a, b);
  while (b < m) {
    a += b;
    swap(a, b);
    out++;
  }
  printf("%I64u\n", out);
  return 0;
}
