#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N];
int seg[N][2];
struct node {
  int dis, ans;
  node(int _ans = 0, int _dis = 0) { ans = _ans, dis = _dis; }
};
node q[N * 5];
int L, n, p, t;
int top, tail;
void solve(int id, node &tmp, node q) {
  int cot = seg[id][1] - max(seg[id][0], q.dis + t);
  cot /= p;
  q.ans += cot;
  q.dis = max(seg[id][0], q.dis + t) + cot * p;
  if (q.ans > tmp.ans || (q.ans == tmp.ans && q.dis < tmp.dis)) {
    tmp = q;
  }
}
int main(int argc, const char *argv[]) {
  scanf("%d%d%d%d", &L, &n, &p, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", seg[i], seg[i] + 1);
  }
  int ans = 0;
  top = tail = 0;
  q[tail++] = node(0, -t);
  for (int i = 1; i <= n; ++i) {
    node tmp(0, seg[i][1]);
    if (top) top--;
    while (top < tail) {
      if (q[top].dis + p + t > tmp.dis) {
        break;
      }
      solve(i, tmp, q[top++]);
    }
    if (ans < tmp.ans) {
      ans = tmp.ans;
      q[tail++] = tmp;
    }
  }
  printf("%d\n", ans);
  return 0;
}
