#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, s, p;
  scanf("%d%d%d%d", &k, &n, &s, &p);
  int x1;
  if (n % s == 0) {
    x1 = n / s;
  } else {
    x1 = n / s + 1;
  }
  int ans;
  if (k * x1 % p == 0) {
    ans = k * x1 / p;
  } else {
    ans = k * x1 % p + 1;
  }
  printf("%d", ans);
}
