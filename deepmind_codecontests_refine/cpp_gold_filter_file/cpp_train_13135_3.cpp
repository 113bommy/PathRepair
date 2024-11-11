#include <bits/stdc++.h>
using namespace std;
int const N = 1000000, B = 20;
int fr[1 << B + 1], x[N];
void ad(int x, int j = 0) {
  if (fr[x] == 2) return;
  ++fr[x];
  for (int i = j; i < (int)(B + 1); ++i)
    if (x >> i & 1) ad(x ^ 1 << i, i + 1);
}
int qu(int x) {
  int an = 0;
  for (int i = B; i >= 0; --i)
    if (!(x >> i & 1) && fr[an ^ 1 << i] == 2) an ^= 1 << i;
  return an ^ x;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", x + i);
  int an = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (i + 2 < n) an = max(an, qu(x[i]));
    ad(x[i]);
  }
  printf("%d\n", an);
}
