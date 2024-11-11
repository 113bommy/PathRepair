#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
int h[1005][1005], bb[1005][1005];
ii dq[1005];
long long sum[1005][1005];
struct Node {
  long long val;
  int x, y;
  Node() {}
  Node(int X, int Y, long long VAL) {
    x = X;
    y = Y;
    val = VAL;
  }
  inline bool operator>(const Node &n) const {
    if (val != n.val) return val > n.val;
    if (x != n.x) return x > n.x;
    return y > n.y;
  }
};
vector<Node> ans;
int main() {
  int n, m, a, b, hd = 1, tl = 0;
  priority_queue<Node, vector<Node>, greater<Node> > pq;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 1; i <= n; i++) {
    hd = 1;
    tl = 0;
    for (int j = 1; j <= m; j++) {
      scanf("%d", h[i] + j);
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + h[i][j];
      if (hd <= tl && dq[hd].second <= j - b) ++hd;
      while (hd <= tl && dq[tl].first > h[i][j]) --tl;
      dq[++tl] = ii(h[i][j], j);
      if (j >= b) h[i][j] = dq[hd].first;
    };
  }
  for (int i = b; i <= m; i++) {
    hd = 1;
    tl = 0;
    for (int j = 1; j <= n; j++) {
      if (hd <= tl && dq[hd].second <= j - a) ++hd;
      while (hd <= tl && dq[tl].first > h[j][i]) --tl;
      dq[++tl] = ii(h[j][i], j);
      if (j >= a) h[j][i] = dq[hd].first;
    }
  }
  for (int i = a; i <= n; i++) {
    for (int j = b; j <= m; j++) {
      pq.push(Node(i, j,
                   sum[i][j] + sum[i - a][j - b] - sum[i - a][j] -
                       sum[i][j - b] - 1ll * h[i][j] * a * b));
    }
  }
  while (!pq.empty()) {
    Node u = pq.top();
    pq.pop();
    if (bb[u.x][u.y] || bb[u.x - a + 1][u.y] || bb[u.x][u.y - b + 1] ||
        bb[u.x - a + 1][u.y - b + 1])
      continue;
    ans.push_back(Node(u.x - a + 1, u.y - b + 1, u.val));
    for (int i = u.x - a + 1; i <= u.x; i++) {
      for (int j = u.y - b + 1; j <= u.y; j++) {
        bb[i][j] = 1;
      }
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d %lld\n", ans[i].x, ans[i].y, ans[i].val);
  }
  return 0;
}
