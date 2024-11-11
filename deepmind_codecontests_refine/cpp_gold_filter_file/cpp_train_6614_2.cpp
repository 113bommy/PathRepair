#include <bits/stdc++.h>
using namespace std;
const int M = 10005;
int a[105][105];
int n, m, q;
struct node {
  int x, y, t, id;
} tmp;
vector<node> cc;
vector<pair<int, int> > r, c;
void rfun(int r) {
  for (int i = m + 1 - 1; i >= 1; --i) {
    a[r][i + 1] = a[r][i];
  }
  a[r][1] = a[r][m + 1];
}
void cfun(int c) {
  for (int i = n + 1 - 1; i >= 1; --i) {
    a[i + 1][c] = a[i][c];
  }
  a[1][c] = a[n + 1][c];
}
void solve() {
  int l = q - 1, i, j, k;
  i = (int)r.size() - 1;
  j = (int)c.size() - 1;
  k = (int)cc.size() - 1;
  while (l >= 0) {
    if (i >= 0 && r[i].second == l) {
      rfun(r[i].first);
      --i;
    }
    if (j >= 0 && c[j].second == l) {
      cfun(c[j].first);
      --j;
    }
    if (k >= 0 && cc[k].id == l) {
      a[cc[k].x][cc[k].y] = cc[k].t;
      --k;
    }
    --l;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  int op, t;
  for (int i = 0; i < q; ++i) {
    scanf("%d", &op);
    if (op < 3) {
      scanf("%d", &t);
      if (op == 1) {
        r.push_back(make_pair(t, i));
      } else {
        c.push_back(make_pair(t, i));
      }
    } else {
      scanf("%d%d%d", &tmp.x, &tmp.y, &tmp.t);
      tmp.id = i;
      cc.push_back(tmp);
    }
  }
  solve();
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) printf("%d ", a[i][j]);
    puts("");
  }
  return 0;
}
