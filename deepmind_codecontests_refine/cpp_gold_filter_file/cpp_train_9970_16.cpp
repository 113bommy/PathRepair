#include <bits/stdc++.h>
using namespace std;
const int N = (int)(1e5 + 5);
const int LOG = (int)(20);
int n;
int main() {
  scanf("%d", &n);
  if (n == 1)
    printf("4\n");
  else if (n == 2)
    printf("10");
  else if (n == 3)
    printf("20");
  else if (n == 4)
    printf("35");
  else if (n == 5)
    printf("56");
  else if (n == 6)
    printf("83");
  else if (n == 7)
    printf("116");
  else if (n == 8)
    printf("155");
  else if (n == 9)
    printf("198");
  else if (n == 10)
    printf("244");
  else
    printf("%lld", 1ll * (n - 11) * 49 + 292);
}
