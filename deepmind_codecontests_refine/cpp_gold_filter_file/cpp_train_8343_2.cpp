#include <bits/stdc++.h>
using namespace std;
struct SE {
  int x, y, c;
} seg[200005];
int cmp(SE a, SE b) { return a.x < b.x; }
int cost[200005];
struct Node {
  int t, c;
  Node(int tt, int cc) {
    t = tt;
    c = cc;
  }
  bool operator<(Node const& ot) const { return t > ot.t; }
};
int n, m;
priority_queue<Node> qq;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &cost[i]);
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &seg[i].x, &seg[i].y, &seg[i].c);
    ans += seg[i].c;
  }
  sort(seg, seg + m, cmp);
  int site = 0;
  for (int i = 1; i <= n; ++i) {
    while (site <= m && seg[site].x == i) {
      qq.push(Node(seg[site].y, seg[site].c));
      site++;
    }
    while (!qq.empty() && qq.top().t < i) qq.pop();
    while (!qq.empty() && cost[i] > 0) {
      Node temp = qq.top();
      qq.pop();
      int ttt = min(temp.c, cost[i]);
      cost[i] -= ttt;
      ans -= ttt;
      temp.c -= ttt;
      if (temp.c > 0) qq.push(temp);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
