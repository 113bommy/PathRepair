#include <bits/stdc++.h>
using namespace std;
long long n, m, d;
int b[20];
void solve() {
  d = 1;
  memset(b, 0, sizeof b);
  int k = 0;
  while (n) {
    b[k] = n % 2;
    n >>= 1;
    k++;
  }
  for (int i = k - 1; i >= 0; i--) {
    d = (d * d) % m;
    if (b[i] == 1) d = (d * 3) % m;
  }
}
int main() {
  scanf("%I64d %I64d", &n, &m);
  solve();
  if (d == 0) {
    printf("%I64d\n", m - 1);
  } else
    printf("%I64d\n", d - 1);
  return 0;
}
