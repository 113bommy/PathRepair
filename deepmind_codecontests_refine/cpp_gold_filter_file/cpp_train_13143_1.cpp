#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int a[N];
int as[N * N], ac = 0;
void f(int i) {
  as[++ac] = i;
  swap(a[i], a[i + 1]);
  swap(a[i], a[i + 2]);
}
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    bool fail = 0;
    int p = 0;
    for (int i = 1; i <= n; ++i) {
      int j = min_element(a + i, a + n + 1) - a;
      while (j > i + 1) f(j - 2), j -= 2;
      if (j == i + 1) {
        if (j <= n - 1)
          f(i), f(i);
        else if (p) {
          f(p - 1), f(p - 1), i = p - 1;
        } else {
          f(i - 1);
          if (!is_sorted(a + i - 1, a + n + 1)) {
            ac = -1;
            break;
          }
        }
      }
      if (a[i] == a[i - 1]) p = i;
    }
    printf("%d\n", ac);
    if (ac == 0) printf("\n");
    if (ac > 0)
      for (int i = 1; i <= ac; ++i) printf("%d%c", as[i], " \n"[i == ac]);
    ac = 0;
  }
  return 0;
}
