#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e3 + 7;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const unsigned long long seed = 1331;
int T;
long long a, b;
int check(long long x) {
  for (int i = 2; i < sqrt(x); i++)
    if (x % i == 0) return 0;
  return 1;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld", &a, &b);
    if ((a - b) == 1 && check(a + b))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
