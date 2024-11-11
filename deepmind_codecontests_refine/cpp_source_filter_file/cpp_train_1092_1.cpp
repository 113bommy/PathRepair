#include <bits/stdc++.h>
const int inf = 99999999;
using namespace std;
struct arry {
  int c[105][105];
};
int n, m;
arry add(arry a, arry b) {
  arry p;
  int i, j, k;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      p.c[i][j] = -inf;
      for (k = 1; k <= n; k++) {
        p.c[i][j] = max(p.c[i][j], a.c[i][k] + b.c[k][j]);
      }
    }
  }
  return p;
}
arry calpow(arry a, int pn) {
  arry tmp;
  int i, j;
  memset(tmp.c, 0, sizeof(tmp.c));
  tmp = a;
  while (pn) {
    if (pn & 1) tmp = add(tmp, a);
    a = add(a, a);
    pn >>= 1;
  }
  return tmp;
}
int main() {
  int i, j, num[105], s, k, t, T;
  arry st;
  while (~scanf("%d %d", &n, &T)) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &num[i]);
    }
    memset(st.c, -1, sizeof(st.c));
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (num[i] > num[j])
          st.c[i][j] = -inf;
        else {
          st.c[i][j] = 1;
          for (k = i; k < j; k++) {
            if (num[k] <= num[j]) {
              st.c[i][j] = max(st.c[i][j], st.c[i][k] + 1);
            }
          }
        }
      }
    }
    st = calpow(st, T - 1);
    int ans = -1;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        ans = max(ans, st.c[i][j]);
      }
    }
    printf("%d\n", ans);
  }
}
