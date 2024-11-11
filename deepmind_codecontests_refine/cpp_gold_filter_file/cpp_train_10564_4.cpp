#include <bits/stdc++.h>
using namespace std;
int a[100005];
vector<int> l;
int cnt0, cnt;
int r = -1;
int main(void) {
  int t;
  scanf("%d", &t);
  for (int(test) = 0; (test) < (t); (test)++) {
    int m, k;
    scanf("%d%d", &m, &k);
    for (int(i) = 0; (i) < (k); (i)++) {
      scanf("%d", &a[i]);
    }
    l.assign(k, -1);
    cnt0 = 0;
    cnt = 0;
    r = -1;
    for (int(i) = 0; (i) < (m - 1); (i)++) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (y) {
        if (r == -1) {
          r = i;
        }
      }
      if (x > 0) {
        a[x - 1]--;
        l[x - 1] = i;
      } else {
        cnt++;
        if (r == -1) {
          cnt0++;
        }
      }
    }
    if (r == -1) {
      for (int(i) = 0; (i) < (k); (i)++) {
        if (a[i] <= cnt) {
          printf("Y");
        } else {
          printf("N");
        }
      }
      printf("\n");
    } else {
      vector<int> ans(k, 0);
      int minV = 100005;
      for (int(i) = 0; (i) < (k); (i)++) {
        if (l[i] < r) {
          if (a[i] <= cnt0) {
            ans[i] = 1;
            minV = min(minV, a[i]);
          }
        }
      }
      cnt -= minV;
      for (int(i) = 0; (i) < (k); (i)++) {
        if (ans[i] == 0) {
          if (a[i] <= cnt) {
            ans[i] = 1;
          }
        }
      }
      for (int(i) = 0; (i) < (k); (i)++) {
        printf(ans[i] ? "Y" : "N");
      }
      printf("\n");
    }
  }
}
