#include <bits/stdc++.h>
using namespace std;
const int maxn = 1600010;
bool b1;
int n, m1, m2, M, head[maxn], ver[maxn * 4], Next[maxn * 4], tot, N, v[maxn];
int dfn[maxn], low[maxn], bel[maxn], ins[maxn], sta[maxn], top, scc, num;
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
void tarjan(int x) {
  dfn[x] = low[x] = ++num;
  sta[++top] = x;
  ins[x] = 1;
  for (int i = head[x]; i; i = Next[i])
    if (!dfn[ver[i]])
      tarjan(ver[i]), low[x] = min(low[x], low[ver[i]]);
    else if (ins[ver[i]])
      low[x] = min(low[x], low[ver[i]]);
  if (dfn[x] == low[x]) {
    scc++;
    int z = 0;
    while (z != x) z = sta[top--], ins[z] = 0, bel[z] = scc;
  }
}
bool b2;
int main() {
  int x, y;
  scanf("%d%d%d%d", &m1, &n, &M, &m2);
  N = n + M + 1;
  for (int i(1), i_ORZ(m1); i <= i_ORZ; i++)
    scanf("%d%d", &x, &y), add(x + N, y), add(y + N, x);
  for (int i(1), i_ORZ(n); i <= i_ORZ; i++) {
    scanf("%d%d", &x, &y);
    add(i, x + n), add(i, y + 1 + n + N);
    add(x + n + N, i + N), add(y + 1 + n, i + N);
  }
  for (int i(1), i_ORZ(M); i <= i_ORZ; i++)
    add(i + n + 1, i + n), add(i + n + N, i + n + N + 1);
  for (int i(1), i_ORZ(m2); i <= i_ORZ; i++)
    scanf("%d%d", &x, &y), add(x, y + N), add(y, x + N);
  for (int i(1), i_ORZ(N + N); i <= i_ORZ; i++)
    if (!dfn[i]) tarjan(i);
  for (int i(1), i_ORZ(N); i <= i_ORZ; i++) {
    if (bel[i] == bel[i + N]) {
      printf("-1\n");
      return 0;
    }
    v[i] = (bel[i] < bel[i + N]);
  }
  int k = 0, F = 0;
  ;
  for (int i(1), i_ORZ(n); i <= i_ORZ; i++)
    if (v[i]) k++;
  for (int i(1), i_ORZ(M); i <= i_ORZ; i++)
    if (v[i + n]) F = i;
  printf("%d %d\n", k, F);
  for (int i(1), i_ORZ(n); i <= i_ORZ; i++)
    if (v[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
