#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int C[maxn];
int n;
int inc;
int lowbit(int x) { return x & -x; }
void add(int x, int v) {
  while (x <= n) {
    C[x] += v;
    x = x + lowbit(x);
  }
}
int sum(int x) {
  int res = 0;
  while (x > 0) {
    res += C[x];
    x = x - lowbit(x);
  }
  return res;
}
int main() {
  int Q;
  scanf("%d%d", &n, &Q);
  inc = 0;
  int flip = 0;
  for (int i = 1; i <= n; i++) add(i, 1);
  for (int _Q = 1; _Q <= Q; ++_Q) {
    int q;
    scanf("%d", &q);
    if (q == 1) {
      int x;
      scanf("%d", &x);
      if (flip) x = n - x;
      if (x > n - x) {
        flip = 1;
        for (int i = x, j = x + 1; j <= n; j++, i--) {
          int c = sum(inc + j) - sum(inc + j - 1);
          add(inc + i, c);
        }
        n = x;
      } else {
        if (flip) flip = 0;
        for (int i = x, j = x + 1; i >= 1; i--, j++) {
          int c = sum(inc + i) - sum(inc + i - 1);
          add(inc + j, c);
        }
        inc += x;
        n = n - x;
      }
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l++;
      if (flip) {
        int t = l;
        l = n - r + 1;
        r = n - t + 1;
      }
      printf("%d\n", sum(r + inc) - sum(l + inc - 1));
    }
  }
  return 0;
}
