#include <bits/stdc++.h>
using namespace std;
long long int a;
int main() {
  scanf("%lld", &a);
  if (a == 1)
    printf("4\n");
  else if (a == 2)
    printf("10\n");
  else if (a == 3)
    printf("20\n");
  else if (a == 4)
    printf("35\n");
  else if (a == 5)
    printf("56\n");
  else if (a == 6)
    printf("83\n");
  else if (a == 7)
    printf("116\n");
  else if (a == 8)
    printf("155\n");
  else if (a == 9)
    printf("198\n");
  else if (a == 10)
    printf("244\n");
  else
    printf("%lld\n", 49ll * (a - 11) + 292);
}
