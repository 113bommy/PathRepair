#include <bits/stdc++.h>
const int N = 100005;
using namespace std;
long long s[15][15][N];
int n, a[N];
void add(int M, int m, int x, long long d) {
  for (; x <= n; x += x & (-x)) s[M][m][x] += d;
}
long long sum(int M, int m, int x) {
  long long res = 0;
  for (; x; x -= x & (-x)) res += s[M][m][x];
  return res;
}
void update(int t, int x) {
  x = x - a[t];
  int i;
  for (i = 2; i <= 10; i += 2) {
    add(i, t % i, t, (long long)x);
  }
  a[t] += x;
}
long long calc(int l, int r, int z) {
  int i, k, p = (z - 1) << 1;
  long long res = 0;
  for (i = 0; i < p; i++) {
    if (i + 1 == p)
      k = 2;
    else if (i < z)
      k = i + 1;
    else
      k = z * 2 - i - 1;
    res += 1LL * k * (sum(p, (l + i) % p, r) - sum(p, (l + i) % p, l - 1));
  }
  return res;
}
int main() {
  int q;
  scanf("%d", &n);
  int i, x;
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    update(i + 1, x);
  }
  scanf("%d", &q);
  int t, l, r, z, p, v;
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &p, &v);
      update(p, v);
    } else {
      scanf("%d%d%d", &l, &r, &z);
      printf("%I64d\n", calc(l, r, z));
    }
  }
  return 0;
}
