#include <bits/stdc++.h>
using namespace std;
int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const int maxn = 1e6 + 10;
vector<int> g[4][maxn];
struct rct {
  int x, y, x2, y2, id;
  inline void read(int v = 0) {
    x = in(), y = in(), x2 = in(), y2 = in(), id = 0;
  }
} rect[maxn];
int res[maxn];
int32_t main() {
  int n = in();
  for (int i = 0; i < n; i++) {
    rect[i].read(i);
    if (rect[i].x % 2) {
      if (rect[i].y % 2) {
        res[i] = 1;
      } else
        res[i] = 2;
    } else {
      if (rect[i].y % 2)
        res[i] = 3;
      else
        res[i] = 4;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) printf("%d\n", res[i]);
}
