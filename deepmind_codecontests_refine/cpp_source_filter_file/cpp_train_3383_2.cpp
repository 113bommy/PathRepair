#include <bits/stdc++.h>
using namespace std;
int p, q;
bool prime[1179759];
bool palin(int x) {
  int tmp = x;
  int ret = 0;
  while (tmp) {
    ret *= 10;
    ret += tmp % 10;
    tmp /= 10;
  }
  return ret == x;
}
int main() {
  for (int i = 2; i < 1179759; i++) prime[i] = 1;
  for (int i = 2; i * i <= 1179759; i++)
    if (prime[i])
      for (int j = 2 * i; j <= 1179759; j += i) prime[j] = 0;
  scanf("%d %d", &p, &q);
  int ans, pi, rub;
  ans = pi = rub = 0;
  for (int i = 1; i < 1179759; i++) {
    pi += prime[i];
    rub += palin(i);
    if (pi <= rub * p / q) ans = i;
  }
  printf("%d\n", ans);
  return 0;
}
