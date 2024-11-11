#include <bits/stdc++.h>
using namespace std;
int n, k;
char op[10];
int cnt = 0;
int f(int ll, int rr) {
  if (ll > rr) return -1;
  if (ll == rr) {
    int x = ll, y = ll + 1, z = ll - 1;
    if (y <= n) {
      printf("1 %d %d\n", x, y);
      ++cnt;
      fflush(stdout);
      scanf("%s", op);
      if (op[0] != 'T') return -1;
    }
    if (z >= 1) {
      printf("1 %d %d\n", x, z);
      ++cnt;
      fflush(stdout);
      scanf("%s", op);
      if (op[0] != 'T') return -1;
    }
    return ll;
  }
  int mid = (ll + rr) / 2;
  int xl = (ll + mid) / 2;
  int xr = (mid + rr) / 2;
  printf("1 %d %d\n", xl, xr);
  ++cnt;
  fflush(stdout);
  scanf("%s", op);
  if (op[0] == 'T') {
    return f(ll, mid);
  } else
    return f(mid + 1, rr);
}
int main() {
  scanf("%d%d", &n, &k);
  int u = f(1, n);
  int v = f(1, u - 1);
  if (v != -1) {
    printf("2 %d %d\n", u, v);
    fflush(stdout);
    return 0;
  }
  int w = f(u + 1, n);
  printf("2 %d %d\n", u, w);
  fflush(stdout);
  return 0;
}
