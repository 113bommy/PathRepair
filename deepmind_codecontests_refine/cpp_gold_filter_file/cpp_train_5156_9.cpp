#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans, b, c, d, e;
  scanf("%1d%1d%1d%1d%1d", &ans, &b, &c, &d, &e);
  long long a = 1ll * (10000 * ans + 1000 * c + 100 * e + 10 * d + b);
  long long aa = (a * a) % 100000;
  long long aaa = (a * aa) % 100000;
  long long aaaa = (a * aaa) % 1000000;
  long long aaaaa = (a * aaaa) % 1000000;
  printf("%05I64d\n", aaaaa % 100000);
  return 0;
}
