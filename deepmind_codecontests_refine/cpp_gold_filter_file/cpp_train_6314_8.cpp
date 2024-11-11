#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long ll_INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10000 + 10;
const long long mod = 1e9 + 7;
int main() {
  long long n, p, loc;
  scanf("%I64d%I64d", &n, &p);
  while (p--) {
    scanf("%I64d", &loc);
    if (loc & 1)
      printf("%I64d\n", (loc + 1) / 2);
    else {
      long long ceng = n;
      while (!(loc & 1)) {
        loc = ceng - loc / 2;
        ceng = loc;
      }
      printf("%I64d\n", n - ceng + (loc + 1) / 2);
    }
  }
}
