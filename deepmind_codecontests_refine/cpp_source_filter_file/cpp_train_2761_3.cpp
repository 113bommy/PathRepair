#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int ca[N], cb[N], n, k, a, b, p, cnta[N], cntb[N];
inline int lowbit(int x) { return x & (-x); }
inline void adda(int i, int val) {
  while (i <= n) {
    ca[i] += val;
    i += lowbit(i);
  }
}
inline void addb(int i, int val) {
  while (i <= n) {
    cb[i] += val;
    i += lowbit(i);
  }
}
inline int qa(int i) {
  int re = 0;
  while (i) {
    re += ca[i];
    i -= lowbit(i);
  }
  return re;
}
inline int qb(int i) {
  int re = 0;
  while (i) {
    re += cb[i];
    i -= lowbit(i);
  }
  return re;
}
int main() {
  cin >> n >> k >> a >> b >> p;
  for (int i = 1; i <= n; i++) cnta[i] = a, cntb[i] = b;
  while (p--) {
    int t, x, y, z;
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d%d", &y, &z);
      t = min(cnta[y], z);
      cnta[y] -= z;
      adda(y, t);
      t = min(cntb[y], z);
      cntb[y] -= z;
      addb(y, t);
    } else {
      scanf("%d", &y);
      int ans1 = qb(y - 1), ans2 = 0;
      if (y + k <= n) ans2 = qa(n) - qa(y + k - 1);
      printf("%d\n", ans1 + ans2);
    }
  }
}
