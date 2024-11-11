#include <bits/stdc++.h>
using namespace std;
long long L, W, B, ans = 0, tmp;
long long gbs, gys;
long long gcd(long long a, long long b) {
  return a % b == 0 ? b : gcd(b, a % b);
}
int main() {
  scanf("%I64d%I64d%I64d", &L, &W, &B);
  if (W < B) {
    tmp = W;
    W = B;
    B = tmp;
  }
  gbs = W / gcd(W, B) * B;
  if (gbs % W != 0 || gbs % B != 0) gbs = 5000000000000000001;
  ans += B * (L / gbs);
  ans += (L % gbs) >= (B - 1) ? B : (L % gbs + 1);
  ans--;
  if (ans == 0) {
    printf("0/1\n");
    return 0;
  }
  gys = gcd(L, ans);
  printf("%I64d/%I64d\n", ans / gys, L / gys);
  return 0;
}
