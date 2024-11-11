#include <bits/stdc++.h>
using namespace std;
class _type {
 public:
  int t, x;
  _type() {}
  _type(int _t, int _x) {
    t = _t;
    x = _x;
  }
};
int ans[200][200];
vector<_type> V;
void Shifting(int n, int m, int r, int c, int v) {
  for (int i = V.size() - 1; i >= 0; i--) {
    if (V[i].t == 1) {
      if (V[i].x == r) {
        c = ((++c) % m) + 1;
      }
    } else {
      if (V[i].x == c) {
        r = ((++r) % n) + 1;
      }
    }
  }
  ans[r][c] = v;
  return;
}
int main() {
  int Case = 1;
  int n, m, q;
  char dump[2];
  while (scanf("%d %d %d", &n, &m, &q) == 3) {
    V.clear();
    memset(ans, 0, sizeof(ans));
    int t, r, c, v;
    for (int Que = 1; Que <= q; Que++) {
      scanf("%d", &t);
      if (t == 1) {
        scanf("%d", &r);
        V.push_back(_type(t, r));
      } else if (t == 2) {
        scanf("%d", &c);
        V.push_back(_type(t, c));
      } else {
        scanf("%d %d %d", &r, &c, &v);
        Shifting(n, m, r, c, v);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        printf("%d ", ans[i][j]);
      }
      puts("");
    }
  }
  return 0;
}
