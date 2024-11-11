#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int c[maxn], w[maxn];
bool flag[maxn];
struct Node {
  int idx, v;
  Node(int idx = 0, int v = 0) : idx(idx), v(v) {}
  bool operator<(const Node& rhs) const { return v > rhs.v; }
};
priority_queue<Node> pq;
long long solve(int n, long long m) {
  long long ans = 0;
  while (!pq.empty()) pq.pop();
  for (int i = 0; i < n; i++) {
    if (c[i] % 100 == 0) {
      flag[i] = 1;
    } else {
      if (m >= c[i] % 100) {
        m -= c[i] % 100;
        flag[i] = 0;
        pq.push(Node(i, (100 - c[i] % 100) * w[i]));
      } else {
        if (pq.empty() || pq.top().v >= (100 - c[i] % 100) * w[i]) {
          ans += (100 - c[i] % 100) * w[i];
          m += 100 - c[i] % 100;
          flag[i] = 1;
        } else {
          ans += pq.top().v;
          flag[pq.top().idx] = 1;
          pq.pop();
          flag[i] = 0;
          pq.push(Node(i, (100 - c[i] % 100) * w[i]));
          m += 100 - c[i] % 100;
        }
      }
    }
  }
  return ans;
}
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    printf("%lld\n", solve(n, m));
    for (int i = 0; i < n; i++) {
      if (flag[i] == 0 || c[i] % 100 == 0)
        printf("%d %d\n", c[i] / 100, c[i] % 100);
      else
        printf("%d %d\n", c[i] / 100 + 1, 0);
    }
  }
  return 0;
}
