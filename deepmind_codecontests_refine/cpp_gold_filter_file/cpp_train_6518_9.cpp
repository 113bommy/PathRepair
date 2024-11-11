#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, c, d, e;
} a[1244];
int b[1234];
int n;
int main() {
  cin >> n;
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d >> a[i].e;
  }
  int ans = 0;
  if (n > 11)
    printf("0\n");
  else {
    for (int i = 1; i <= n; i++) {
      int flag = 1;
      for (int j = 1; j <= n; j++) {
        int aa = a[i].a - a[j].a;
        int bb = a[i].b - a[j].b;
        int cc = a[i].c - a[j].c;
        int dd = a[i].d - a[j].d;
        int ee = a[i].e - a[j].e;
        for (int k = 1; k <= n; k++) {
          if (i != j && j != k && k != i) {
            int aaa = a[i].a - a[k].a;
            int bbb = a[i].b - a[k].b;
            int ccc = a[i].c - a[k].c;
            int ddd = a[i].d - a[k].d;
            int eee = a[i].e - a[k].e;
            int ans1 = aa * aaa + bb * bbb + cc * ccc + dd * ddd + ee * eee;
            if (ans1 <= 0) {
              continue;
            } else {
              flag = 0;
              break;
            }
          } else
            continue;
        }
        if (flag == 0) break;
      }
      if (flag) {
        ans++;
        b[i]++;
      }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      if (b[i]) printf("%d\n", i);
    }
  }
  return 0;
}
