#include <bits/stdc++.h>
using namespace std;
int q, n, sum, r, x;
int go(int x) {
  x %= n;
  while (x <= 0) x += n;
  return x;
}
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &n, &r);
    sum = 0;
    for (int i = 0; i < n - 1; i++) scanf("%d", &x), sum += x;
    printf("%d\n", go(sum + r) % n + 1);
  }
  return 0;
}
