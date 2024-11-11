#include <bits/stdc++.h>
using namespace std;
long long add(long long a, long long b, long long m) {
  if ((a += b) >= m) a -= m;
  return a;
}
long long mult(long long a, long long b, long long m) {
  long long res = 0;
  while (b) {
    if (b & 1) res = add(res, a, m);
    a = add(a, a, m);
    b >>= 1;
  }
  return res;
}
void solve() {
  long long p, q, b;
  scanf("%lld%lld%lld", &p, &q, &b);
  b %= q;
  p %= q;
  for (int i = 0; i < 6; i++) b = mult(b, b, q);
  if (mult(b, p, q) == 0) {
    printf("Finite\n");
  } else {
    printf("Infinite\n");
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) solve();
}
