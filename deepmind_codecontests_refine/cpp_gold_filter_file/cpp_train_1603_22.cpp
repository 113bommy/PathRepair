#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Operation {
  int x;
  int y;
  int id;
  bool operator<(Operation const &a) const {
    return x == a.x ? y > a.y : x < a.x;
  }
};
Operation q[N];
int n, m, k, flag, ans[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, l;
    scanf("%d%d", &x, &l);
    q[i] = (Operation){x, x + l - 1, i};
  }
  sort(q + 1, q + 1 + m);
  for (int i = 1; i <= m; i++)
    if (q[i].x > flag) {
      int j, mx = q[i].y, mxj = i;
      for (j = i + 1; j <= m; j++) {
        if (q[j].x > q[i].y + 1) break;
        if (q[j].y > mx) {
          mx = q[j].y;
          mxj = j;
        }
      }
      ans[++k] = q[i].id;
      if (mx == q[i].y)
        flag = q[i].y;
      else
        flag = q[mxj].x - 1;
    }
  sort(ans + 1, ans + 1 + k);
  printf("%d\n", m - k);
  for (int i = 1; i <= m; i++)
    if ((*lower_bound(ans + 1, ans + 1 + k, i)) != i) printf("%d ", i);
  return 0;
}
