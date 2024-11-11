#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const double PI = acos(-1);
const double ERR = 1e-10;
int main() {
  int x;
  scanf("%d", &x);
  if (x == 3)
    printf("13\n");
  else if (x == 0)
    printf("15\n");
  else if (x == 1)
    printf("14\n");
  else if (x == 2)
    printf("12\n");
  else if (x == 4)
    printf("8\n");
  else if (x == 5)
    printf("9\n");
  else if (x == 6)
    printf("10\n");
  else if (x == 7)
    printf("11\n");
  else if (x == 8)
    printf("0\n");
  else if (x == 9)
    printf("1\n");
  else if (x == 10)
    printf("2\n");
  else
    printf("%d\n", x - 8);
  return 0;
}
