#include <bits/stdc++.h>
using namespace std;
int x[4], y[4], r[4], ans;
inline int sqr(int a) { return a * a; }
int main() {
  scanf("%d%d%d%d", x + 0, y + 0, r + 0, r + 1);
  scanf("%d%d%d%d", x + 2, y + 2, r + 2, r + 3);
  x[1] = x[0], y[1] = y[0];
  x[3] = x[2], y[3] = y[2];
  for (int i = 0; i < 4; i++) {
    int flag = 1;
    for (int j = 0; j < 4; j++) {
      if (sqr(x[j] - x[i]) + sqr(y[j] - y[i]) < sqr(r[j] + r[i]) &&
          sqr(x[j] - x[i]) + sqr(y[j] - y[i]) > sqr(r[j] - r[i]))
        flag = 0;
    }
    if (sqr(x[1] - x[i]) + sqr(y[1] - y[i]) <= sqr(r[1] - r[i]) && r[1] > r[i])
      if (!(sqr(x[0] - x[i]) + sqr(y[0] - y[i]) <= sqr(r[0] - r[i]) &&
            r[0] >= r[i]))
        flag = 0;
    if (sqr(x[3] - x[i]) + sqr(y[3] - y[i]) <= sqr(r[3] - r[i]) && r[3] > r[i])
      if (!(sqr(x[2] - x[i]) + sqr(y[2] - y[i]) <= sqr(r[2] - r[i]) &&
            r[2] >= r[i]))
        flag = 0;
    ans += flag;
  }
  cout << ans << endl;
}
