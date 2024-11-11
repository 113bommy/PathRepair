#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1, n;
  long long d, b, c;
  scanf("%d", &n);
  scanf("%I64d", &d);
  scanf("%I64d", &c);
  for (int i = 1; i < n; i++) {
    scanf("%I64d", &b);
    if ((b - d) - (c + d) == 0) t++;
    if ((b - d) - (c + d) > 0) t += 2;
    c = b;
  }
  printf("%d ", ++t);
  return 0;
}
