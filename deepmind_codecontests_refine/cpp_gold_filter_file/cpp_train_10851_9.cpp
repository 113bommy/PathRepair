#include <bits/stdc++.h>
using namespace std;
int n, m, seq[1005];
int cal(int num) {
  int ret = 0;
  for (; num; num -= num & -num, ret++)
    ;
  return ret;
}
int info[1005], Prev[1005 * 1005], to[1005 * 1005], cap[1005 * 1005],
    cst[1005 * 1005], cnt_e = 1;
void Node(int u, int v, int c, int ct) {
  cnt_e++;
  Prev[cnt_e] = info[u], info[u] = cnt_e, to[cnt_e] = v, cap[cnt_e] = c,
  cst[cnt_e] = ct;
}
void Line(int u, int v, int c, int ct) {
  Node(u, v, c, ct);
  Node(v, u, 0, -ct);
}
int S, T;
int dis[1005], pre[1005], Q[1005 * 1005];
bool inq[1005];
int L, R;
bool Spfa() {
  for (int i = S; i <= T; i++) dis[i] = 100000;
  L = R = 0, dis[Q[R++] = T] = 0;
  inq[T] = 1;
  for (int now; L < R;) {
    inq[now = Q[L++]] = 0;
    for (int i = info[now]; i; i = Prev[i])
      if (cap[i ^ 1] && dis[to[i]] > dis[now] + cst[i ^ 1]) {
        pre[to[i]] = i ^ 1;
        dis[to[i]] = dis[now] + cst[i ^ 1];
        if (!inq[to[i]]) inq[Q[R++] = to[i]] = 1;
      }
  }
  return dis[S] < 100000;
}
int cost;
void aug() {
  cost += dis[S];
  for (int i = S; i != T; i = to[pre[i]]) {
    cap[pre[i]]--;
    cap[pre[i] ^ 1]++;
  }
}
int ck1[1005 * 1005];
int ck2[1005], isfree[1005];
queue<int> q;
int main() {
  scanf("%d%d", &n, &m);
  T = 2 * n + 1;
  for (int i = 1; i <= n; i++) scanf("%d", &seq[i]);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      if (i != j) {
        Line(i + n, j, 1, (seq[i] == seq[j]) ? 0 : cal(seq[j]));
        if (seq[i] == seq[j]) ck1[++ck1[0]] = cnt_e;
      } else
        Line(i, i + n, 1, -100000);
  for (int i = 1; i <= n; i++) Line(S, i, 1, cal(seq[i])), Line(i + n, T, 1, 0);
  int M = m;
  for (; Spfa() && M; aug(), M--)
    if (dis[S] > 0) break;
  int CK1 = 0;
  for (int i = 1; i <= ck1[0]; i++)
    if (cap[ck1[i]]) CK1++;
  printf("%d %d\n", n + n - CK1, cost + n * 100000);
  memset(ck2, -1, sizeof ck2);
  for (int i = 0; i < m; i++) q.push(i);
  for (int i = 1; i <= n; i++) {
    if (ck2[i] == -1) ck2[i] = q.front(), q.pop();
    if (!isfree[i]) printf("%c=%d\n", ck2[i] + 'a', seq[i]);
    printf("print(%c)\n", ck2[i] + 'a');
    bool flag = 0;
    for (int j = info[i + n]; j; j = Prev[j])
      if (to[j] && to[j] <= n && !cap[j]) {
        flag = 1;
        if (seq[i] == seq[to[j]]) isfree[to[j]] = 1;
        ck2[to[j]] = ck2[i];
      }
    if (!flag) q.push(ck2[i]);
  }
}
