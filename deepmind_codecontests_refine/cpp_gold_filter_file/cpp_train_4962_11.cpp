#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, t;
long long res = 0;
int table[1000 + 5];
int main() {
  scanf("%d %d %d %d %d", &n, &a, &b, &c, &t);
  for (int i = 0; i < n; i++) {
    int ad;
    scanf("%d", &ad);
    if (c >= b) {
      res += (t - ad) * (c - b) + a;
    } else {
      res += a;
    }
  }
  printf("%lld\n", res);
  return 0;
}
