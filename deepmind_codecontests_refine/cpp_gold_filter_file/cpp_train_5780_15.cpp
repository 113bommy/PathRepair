#include <bits/stdc++.h>
using namespace std;
typedef struct A {
  int val;
  int in;
  int o;
} edge;
edge a[100001];
int cmp(edge x, edge y) {
  if (x.val != y.val)
    return x.val < y.val;
  else
    return x.in > y.in;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].val >> a[i].in;
    a[i].o = i;
  }
  sort(a + 1, a + m + 1, cmp);
  int flag = 1, u = 2, v = 3, t = 2;
  int ans[100001][3] = {0};
  for (int i = 1; i <= m; i++) {
    if (a[i].in == 1) {
      ans[a[i].o][1] = 1;
      ans[a[i].o][2] = t++;
    } else {
      if (v >= t) {
        cout << -1 << endl;
        flag = 0;
        break;
      } else {
        ans[a[i].o][1] = u;
        ans[a[i].o][2] = v;
        u++;
        if (u == v) {
          u = 2;
          v++;
        }
      }
    }
  }
  if (flag)
    for (int i = 1; i <= m; i++) cout << ans[i][1] << " " << ans[i][2] << endl;
  return 0;
}
