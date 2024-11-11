#include <bits/stdc++.h>
using namespace std;
int ans[110000], add[110000];
int n, m, a, cnt, me;
char temp[3];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) ans[i] = 1, add[i] = 0;
    ;
    cnt = 0;
    me = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%s%d", temp, &a);
      if (*temp == '+') {
        if (!me || (me == a))
          me = a;
        else
          ans[a] = 0;
        add[a] = 1;
        if (a != me && !add[me]) ans[me] = 0, me = 0;
        cnt++;
      } else {
        if (!me) me = a;
        if (a != me && add[a] == 0) {
          ans[me] = 0;
          me = a;
        }
        if (add[a]) {
          add[a] = 0;
          cnt--;
        }
        if (cnt) ans[a] = 0;
      }
    }
    int tt = 0;
    bool fi = true;
    for (int i = 1; i <= n; i++)
      if (ans[i]) tt++;
    printf("%d\n", tt);
    for (int i = 1; i <= n; i++) {
      if (ans[i]) {
        if (!fi) printf(" ");
        printf("%d", i);
        fi = false;
      }
    }
    printf("\n");
  }
  return 0;
}
