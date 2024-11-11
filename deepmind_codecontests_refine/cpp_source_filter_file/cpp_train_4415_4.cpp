#include <bits/stdc++.h>
using namespace std;
struct ww {
  int a, c;
  vector<int> b;
} a[100010];
struct w {
  int f1, f2, ma, mi;
} b[100010];
int i, j, k, n, m, x, y;
int f[100010], sheng[100010], s[100010];
vector<int> c[100010], d[100010];
struct dui {
  int x, y;
  inline bool operator<(const dui &A) const {
    return x > A.x || x == A.x && s[y] < s[A.y];
  }
};
priority_queue<dui> Q;
void dfs(int x) {
  if (f[x]) return;
  int i, j;
  f[x] = 2;
  b[x].f1 = 1;
  for (i = 0; i < d[x].size(); i++) {
    ww A = a[d[x][i]];
    int F = 0, s2 = A.a, flag = 0;
    for (j = 0; j < A.b.size(); j++) {
      int B = A.b[j];
      if (!b[B].f1) {
        flag = 1;
        break;
      }
      if (f[B] == 2)
        F = 1;
      else {
        dfs(B);
        F |= b[B].f2;
        s2 = min(s2 + b[B].ma, 314000000);
      }
    }
    if (flag) continue;
    if (!F)
      b[x].ma = max(b[x].ma, s2);
    else
      b[x].f2 = 1;
  }
  f[x] = 1;
}
int main() {
  scanf("%d%d", &m, &n);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    ww A = {};
    A.c = x;
    for (j = 1; j <= y; j++) {
      scanf("%d", &k);
      if (k < 0)
        A.a++;
      else {
        A.b.push_back(k);
        c[k].push_back(i);
      }
    }
    d[x].push_back(i);
    a[i] = A;
    sheng[i] = A.b.size();
    s[i] = A.a;
    Q.push((dui){sheng[i], i});
  }
  for (i = 1; i <= n; i++) b[i].mi = 314000000;
  for (; !Q.empty();) {
    dui A = Q.top();
    Q.pop();
    int B = a[A.y].c;
    if (A.x) break;
    b[B].mi = min(b[B].mi, s[A.y]);
    if (b[B].f1) continue;
    b[B].f1 = 1;
    for (i = 0; i < c[B].size(); i++) {
      int C = c[B][i];
      sheng[C]--;
      s[C] = min(s[C] + b[B].mi, 314000000);
      Q.push((dui){sheng[C], C});
    }
  }
  for (i = 1; i <= n; i++)
    if (b[i].f1 && !f[i]) dfs(i);
  for (i = 1; i <= n; i++) {
    if (!b[i].f1)
      printf("-1 -1\n");
    else
      printf("%d %d\n", b[i].mi, b[i].f2 ? -2 : b[i].ma);
  }
  return 0;
}
