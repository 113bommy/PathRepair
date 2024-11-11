#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d = -1, i = 0;
int main() {
  scanf("%d%d%d", &a, &b, &c);
  a = a % b;
  while (d != c) {
    d = a * 10 / b;
    a = a * 10 % b;
    i++;
    if (i > 1000000) break;
  }
  if (i <= 6)
    printf("%d", i);
  else
    printf("-1");
}
