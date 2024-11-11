#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int r[maxn];
int jl[maxn];
int n, m, k, v;
void cl(int x, int b) {
  jl[x]++;
  for (int i = b; i <= 9; i++) {
    if (((x >> i) & 1) == 0) {
      int nx = (x | (1 << i));
      cl(nx, i);
    }
  }
}
struct node {
  int f, v1, v2, id1, id2;
} pi[maxn];
struct newt {
  int first, second, id;
} p[maxn];
int cnt = 0;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k);
    int x, temp = 0;
    while (k--) {
      scanf("%d", &x);
      temp |= (1 << x);
    }
    r[i] = temp;
  }
  for (int i = 1; i <= n; i++) {
    cl(r[i], 1);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &v);
    scanf("%d", &k);
    int x, temp = 0;
    while (k--) {
      scanf("%d", &x);
      temp |= (1 << x);
    }
    if (pi[temp].f == 0)
      pi[temp].f = 1, pi[temp].v1 = v, pi[temp].id1 = i;
    else if (pi[temp].f == 1)
      pi[temp].f = 2, pi[temp].v2 = v, pi[temp].id2 = i;
    else if (pi[temp].f == 2) {
      int vt = pi[temp].v1, idt = pi[temp].id1;
      if (v < vt) {
        pi[temp].v1 = v, pi[temp].id1 = i;
        if (vt < pi[temp].v2) pi[temp].v2 = vt, pi[temp].id2 = idt;
      } else {
        if (v < pi[temp].v2) pi[temp].v2 = v, pi[temp].id2 = i;
      }
    }
  }
  for (int i = 0; i <= (1 << 10); i++) {
    if (pi[i].f == 1) {
      p[++cnt].first = i;
      p[cnt].second = pi[i].v1, p[cnt].id = pi[i].id1;
    } else if (pi[i].f == 2) {
      p[++cnt].first = i;
      p[cnt].second = pi[i].v1, p[cnt].id = pi[i].id1;
      p[++cnt].first = i;
      p[cnt].second = pi[i].v2, p[cnt].id = pi[i].id2;
    }
  }
  int ans1, ans2, gs = -1, sum = 1e9 + 7;
  for (int i = 1; i <= cnt; i++)
    for (int j = i + 1; j <= cnt; j++) {
      int now = (p[i].first | p[j].first), v = (p[i].second + p[j].second);
      int res = jl[now];
      if (res > gs) {
        gs = res;
        sum = v;
        ans1 = p[i].id, ans2 = p[j].id;
      } else if (res == gs && v < sum) {
        gs = res, sum = v, ans1 = p[i].id, ans2 = p[j].id;
      }
    }
  printf("%d %d\n", ans1, ans2);
}
