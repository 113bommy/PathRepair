#include <bits/stdc++.h>
using namespace std;
int p, q;
int a, b, n;
long long num;
int max_com(int p, int q) {
  int t;
  while (q != 0) {
    t = p % q;
    p = q;
    q = t;
  }
  return p;
}
int main() {
  scanf("%d%d%d%d%d", &n, &a, &b, &p, &q);
  num = n / (a / max_com(a, b)) / b;
  printf("%I64d\n", (n / a - num) * p + (n / b - num) * q + num * max(p, q));
  return 0;
}
