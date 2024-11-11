#include <bits/stdc++.h>
using namespace std;
int n;
inline int read() {
  register int ch = getchar();
  while ((ch ^ '-') && !isdigit(ch)) ch = getchar();
  register int rtn = 0, f = 1;
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) rtn = rtn * 10 + ch - '0', ch = getchar();
  return f * rtn;
}
struct t1 {
  int to, nxt;
} edge[1000006];
int cnt_edge = 0;
int fst[1000006];
inline void addedge(int x, int y) {
  edge[++cnt_edge].to = y;
  edge[cnt_edge].nxt = fst[x];
  fst[x] = cnt_edge;
}
int fth[1000006], val[1000006];
int sum_all, ave;
int sum[1000006];
int root;
int ans[1000006], cnt_ans = 0;
void dfs(int now) {
  sum[now] = val[now];
  for (int tmp = fst[now]; tmp; tmp = edge[tmp].nxt) {
    int aim = edge[tmp].to;
    dfs(aim);
    sum[now] += sum[aim];
  }
  if (sum[now] == ave && (now ^ root)) ans[++cnt_ans] = now, sum[now] = 0;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    fth[i] = read();
    val[i] = read(), sum_all += val[i];
    if (!fth[i])
      root = i;
    else
      addedge(fth[i], i);
  }
  if (sum_all % 3) return puts("-1"), 0;
  ave = sum_all / 3;
  dfs(root);
  if (cnt_ans >= 2)
    printf("%d %d", ans[1], ans[2]);
  else
    puts("-1");
  return 0;
}
