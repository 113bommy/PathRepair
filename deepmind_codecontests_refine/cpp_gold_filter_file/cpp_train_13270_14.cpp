#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
int n, l, e[2 * 500010], a[2 * 500010], u[100010], p[100010];
vector<int> m[100010];
queue<int> q;
int dfs(int i, int l, int f) {
  int j, k, r;
  if (!f || i == l) return f;
  for (r = 0; p[i] < m[i].size(); p[i]++)
    if (u[e[j = m[i][p[i]]]] == u[i] + 1) {
      k = dfs(e[j], l, min(f, a[j]));
      a[j] -= k;
      a[j ^ 1] += k;
      f -= k;
      r += k;
      if (!f) break;
    }
  return r;
}
bool bfs(int b, int l) {
  int i, j;
  for (i = 0; i < n; u[i] = 0, p[i] = 0, i++)
    ;
  for (q.push(b), u[b] = 1; !q.empty();)
    for (i = q.front(), q.pop(), j = 0; j < m[i].size(); j++)
      if (a[m[i][j]] && !u[e[m[i][j]]]) {
        u[e[m[i][j]]] = u[i] + 1;
        q.push(e[m[i][j]]);
      }
  return u[l] > 0;
}
int mxfl(int b, int e) {
  int f;
  for (f = 0; bfs(b, e); f += dfs(b, e, 11000))
    ;
  return f;
}
void add(int i, int j, int c) {
  e[l] = j;
  a[l] = c;
  m[i].push_back(l++);
  e[l] = i;
  a[l] = 0;
  m[j].push_back(l++);
}
void clr() {
  int i;
  l = 0;
  for (i = 0; i < n; m[i].clear(), i++)
    ;
}
int r, c, w[500][25][25], uu[25][25],
    di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1}, ff, mm, t[500], pi[500],
    pj[500];
char g[25][25];
void push(int i, int j, int v) {
  if (i >= 0 && i < r && j >= 0 && j < c && g[i][j] == '.' && uu[i][j] == 500) {
    uu[i][j] = v;
    q.push(i);
    q.push(j);
  }
}
void bfss(int bi, int bj) {
  int i, j, k;
  for (i = 0; i < r; i++)
    for (j = 0; j < c; uu[i][j] = 500, j++)
      ;
  push(bi, bj, 0);
  for (; !q.empty();) {
    i = q.front();
    q.pop();
    j = q.front();
    q.pop();
    for (k = 0; k < 4; push(i + di[k], j + dj[k], uu[i][j] + 1), k++)
      ;
  }
}
int main() {
  int i, j, k, p;
  long long ll, rr, cc;
  scanf("%d%d%d%d", &r, &c, &ff, &mm);
  for (i = 0; i < r; scanf("%s", g[i]), i++)
    ;
  if (ff + 1 != mm && ff - 1 != mm) {
    printf("-1\n");
    return 0;
  }
  if (ff + 1 == mm) {
    scanf("%d%d%d", &pi[ff], &pj[ff], &t[ff]);
    pi[ff]--;
    pj[ff]--;
  } else {
    scanf("%d%d%d", &pi[ff + mm], &pj[ff + mm], &t[ff + mm]);
    pi[ff + mm]--;
    pj[ff + mm]--;
  }
  k = (ff + mm + 1) / 2;
  for (i = 0; i < ff;
       scanf("%d%d%d", &pi[i], &pj[i], &t[i]), pi[i]--, pj[i]--, i++)
    ;
  for (i = 0; i < mm; scanf("%d%d%d", &pi[k + i], &pj[k + i], &t[k + i]),
      pi[k + i]--, pj[k + i]--, i++)
    ;
  for (p = 0; p < 2 * k; p++) {
    bfss(pi[p], pj[p]);
    for (i = 0; i < r; i++)
      for (j = 0; j < c; w[p][i][j] = uu[i][j], j++)
        ;
  }
  for (ll = 0, rr = 10000000000000ll; ll < rr;) {
    cc = (ll + rr) / 2;
    n = 2 * k + r * c * 2 + 2;
    for (i = 0; i < r; i++)
      for (j = 0; j < c;
           add(2 * k + i * c + j, 2 * k + r * c + i * c + j, 1), j++)
        ;
    for (p = 0; p < k; p++) {
      add(n - 2, p, 1);
      add(k + p, n - 1, 1);
      for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
          if (g[i][j] == '.') {
            if (w[p][i][j] < 500 && (long long)w[p][i][j] * t[p] <= cc)
              add(p, 2 * k + i * c + j, 1);
            if (w[k + p][i][j] < 500 &&
                (long long)w[k + p][i][j] * t[k + p] <= cc)
              add(2 * k + r * c + i * c + j, k + p, 1);
          }
    }
    if (mxfl(n - 2, n - 1) == k)
      rr = cc;
    else
      ll = cc + 1;
    clr();
  }
  if (rr >= 10000000000000ll)
    printf("-1\n");
  else
    printf("%lld\n", rr);
  return 0;
}
