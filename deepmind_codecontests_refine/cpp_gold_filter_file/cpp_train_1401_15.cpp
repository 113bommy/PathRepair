#include <bits/stdc++.h>
const int maxn = 6000 + 300;
struct exshai {
  static const int maxq = 18003000;
  int a[maxq], q[maxq];
  int lq;
  void preset() {
    lq = 0;
    memset(a, 0, sizeof(a));
    for (int i = 2; i < maxq; i++) {
      if (!a[i]) q[++lq] = i;
      for (int j = 1; j <= lq && i * q[j] < maxq; j++) {
        a[i * q[j]] = q[j];
        if (!(i % q[j])) break;
      }
    }
  }
  bool check(int x) { return !a[x]; }
  bool divide(int x, int &p1, int &p2) {
    for (int i = 2; q[i] <= x >> 1; i++)
      if (!a[x - q[i]]) {
        p1 = q[i];
        p2 = x - q[i];
        return 1;
      }
    return 0;
  }
} tool1;
int n, p, q, t;
int a[maxn];
int main() {
  scanf("%d", &n);
  if (n == 2) {
    printf("1 1\n");
    return 0;
  }
  tool1.preset();
  if (!((n * n + n) & 3)) {
    tool1.divide(n * (n + 1) / 2, p, q);
    for (t = n; p >= t; t--) p -= t, a[t] = 1;
    a[p] = 1;
    for (int i = 1; i <= n; i++) printf("%d ", a[i] + 1);
    printf("\n");
  } else {
    if (tool1.check((n * n + n) / 2 - 2)) {
      printf("1 2 ");
      for (int i = 3; i <= n; i++) printf("1 ");
      printf("\n");
    } else {
      printf("1 1 ");
      tool1.divide((n * n + n) / 2 - 3, p, q);
      for (t = n; p >= t; t--) p -= t, a[t] = 1;
      if (p >= 3)
        a[p] = 1;
      else {
        a[t + 1] = 0;
        a[t + 1 - 3 + p] = 1;
        a[3] = 1;
      }
      for (int i = 3; i <= n; i++) printf("%d ", a[i] + 2);
      printf("\n");
    }
  }
  return 0;
}
