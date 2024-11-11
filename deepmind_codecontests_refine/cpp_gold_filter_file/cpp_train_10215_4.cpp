#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int Lim = 22;
const int N = 1e6 + 5;
struct Vector {
  int a[30], len;
  int &operator[](int x) { return a[x]; }
} Now, st[N];
int val[N];
int k;
int key[N], n;
int dis[300][2005];
map<unsigned long long, int> id;
void dfs(int x, int sum, int pre) {
  k++;
  st[k].len = x - 1;
  for (int i = 1; i <= x - 1; i++) st[k][i] = Now[i];
  unsigned long long t = 0;
  for (int i = 1; i <= x - 1; i++) t = t * 97 + Now[i];
  id[t] = k;
  val[k] = 1;
  for (int i = 1; i <= x - 1; i++) val[k] *= Now[i] + 1;
  for (int i = pre; i <= Lim - sum; i++) {
    Now[x] = i;
    dfs(x + 1, sum + i, i);
  }
}
int lst[N], pri[N], m;
bool bz[N];
int pt[N], u;
struct edge {
  int x, nxt;
} e[N];
int h[N], tot;
void inse(int x, int y) {
  e[++tot].x = y;
  e[tot].nxt = h[x];
  h[x] = tot;
}
int que[N], Dis[N];
int Id[N], ins[N];
int cv[N];
int ans[300][300];
void prepare() {
  dfs(1, 0, 1);
  m = 0;
  for (int i = 2; i <= 1e6; i++) {
    if (!lst[i]) pri[++m] = lst[i] = i;
    for (int j = 1; j <= m; j++) {
      if (1ll * i * pri[j] > 1e6) break;
      lst[i * pri[j]] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
  lst[1] = 1;
  for (int i = 1; i <= 1e6; i++) {
    u = 0;
    cv[i] = 1;
    for (int x = i; x > 1;) {
      int v = lst[x];
      pt[++u] = 0;
      for (; x % v == 0; x /= v, pt[u]++)
        ;
      cv[i] *= pt[u] + 1;
    }
    sort(pt + 1, pt + 1 + u);
    unsigned long long t = 0;
    for (int x = 1; x <= u; x++) t = t * 97 + pt[x];
    bz[ins[i] = id[t]] = 1;
  }
  n = 0;
  for (int i = 1; i <= k; i++)
    if (bz[i]) key[Id[i] = ++n] = i;
  for (int i = 1; i <= k; i++) {
    Vector tmp = st[i];
    for (int x = 1; x <= st[i].len; x++)
      for (int c = 0; c <= 1; c++) {
        tmp[x] += c * 2 - 1;
        sort(tmp.a + 1, tmp.a + 1 + st[i].len);
        unsigned long long t = 0;
        if (tmp[1])
          for (int w = 1; w <= st[i].len; w++) t = t * 97 + tmp[w];
        else
          for (int w = 2; w <= st[i].len; w++) t = t * 97 + tmp[w];
        if (id[t]) inse(i, id[t]);
        tmp = st[i];
      }
    tmp[st[i].len + 1] = 1;
    sort(tmp.a + 1, tmp.a + 2 + st[i].len);
    unsigned long long t = 0;
    for (int w = 1; w <= st[i].len + 1; w++) t = t * 97 + tmp[w];
    if (id[t]) inse(i, id[t]);
  }
  for (int w = 1; w <= n; w++) {
    int St = key[w];
    for (int i = 1; i <= k; i++) Dis[i] = -1;
    Dis[St] = 0;
    int he = 0, ta = 1;
    que[1] = St;
    for (; he < ta;) {
      int x = que[++he];
      for (int p = h[x]; p; p = e[p].nxt)
        if (Dis[e[p].x] == -1) {
          Dis[e[p].x] = Dis[x] + 1;
          que[++ta] = e[p].x;
        }
    }
    for (int i = 1; i <= 2000; i++) dis[w][i] = 1e9;
    for (int i = 1; i <= k; i++)
      if (Dis[i] != -1 && val[i] <= 2000)
        dis[w][val[i]] = min(dis[w][val[i]], Dis[i]);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      ans[i][j] = 1e9;
      for (int x = 1; x <= 2000; x++)
        if (dis[i][x] != -1 && dis[j][x] != -1)
          ans[i][j] = min(ans[i][j], dis[i][x] + dis[j][x]);
    }
}
int main() {
  prepare();
  for (int T = get(); T; T--) {
    int a = get(), b = get();
    a = Id[ins[a]];
    b = Id[ins[b]];
    printf("%d\n", ans[a][b]);
  }
  return 0;
}
