#include <bits/stdc++.h>
using namespace std;
int _min(int x, int y) { return x < y ? x : y; }
int _max(int x, int y) { return x > y ? x : y; }
const int N = 22;
int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
void put(int x) {
  if (x >= 10) put(x / 10);
  putchar(x % 10 + '0');
}
int ans[2][N];
struct node {
  int s, t, d, id;
} q[N];
int n, P, bin[N + 1], o[N], last[1 << N];
int d[N], st[N], ed[N], f[1 << N];
bool cmp1(node a, node b) { return a.s < b.s; }
bool cmp2(int a, int b) { return q[a].d < q[b].d; }
void dp() {
  memset(f, -1, sizeof(f));
  f[0] = 1;
  for (int i = 0; i < bin[n]; i++)
    if (f[i] != -1) {
      int k = 0;
      for (; k < n && q[k].s <= f[i]; k++)
        ;
      if (k == n) continue;
      int m = _max(f[i], !k ? -1 : q[k - 1].t + 1), l = q[k].s - m - 1;
      for (int j = 0; j < n; j++) {
        if (i & bin[o[j]]) continue;
        for (; k <= o[j] && l < q[o[j]].d; k++)
          if (i & bin[k] || m == q[k].s)
            m = q[k].t + 1, l = q[k + 1].s - m - 1;
          else
            l += q[k + 1].s - q[k].s;
        if (k > o[j]) continue;
        if (f[i ^ bin[o[j]]] == -1)
          f[i ^ bin[o[j]]] = m + q[o[j]].d, last[i ^ bin[o[j]]] = o[j];
        else if (f[i ^ bin[o[j]]] > m + q[o[j]].d)
          f[i ^ bin[o[j]]] = m + q[o[j]].d, last[i ^ bin[o[j]]] = o[j];
      }
    }
}
void gao(int o, int S) {
  if (!S) return;
  ans[0][q[last[S]].id] = o;
  ans[1][q[last[S]].id] = f[S] - q[last[S]].d;
  gao(o, S ^ bin[last[S]]);
}
bool solve1() {
  if (f[bin[n] - 1] == -1) return 0;
  gao(1, bin[n] - 1);
  return 1;
}
bool solve2() {
  for (int i = 0; i < bin[n]; i++)
    if (f[i] != -1 && f[(bin[n] - 1) ^ i] != -1) {
      gao(1, i), gao(2, (bin[n] - 1) ^ i);
      return 1;
    }
  return 0;
}
int main() {
  n = read(), P = read();
  bin[0] = 1;
  for (int i = 1; i <= n; i++) bin[i] = bin[i - 1] << 1;
  for (int i = 0; i < n; i++)
    q[i].s = read(), q[i].t = read() + q[i].s - 1, q[i].d = read(), q[i].id = i;
  sort(q, q + n, cmp1);
  for (int i = 0; i < n; i++) o[i] = i;
  sort(o, o + n, cmp2);
  dp();
  bool bk;
  if (P == 1)
    bk = solve1();
  else
    bk = solve2();
  if (!bk)
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < n; i++)
      put(ans[0][i]), putchar(' '), put(ans[1][i]), puts("");
  }
  return 0;
}
