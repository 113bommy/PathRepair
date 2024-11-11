#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int M = 1e5 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
struct node {
  int val, cost, id;
  bool operator<(const node& a) const { return cost > a.cost; }
};
int n, m, s;
pair<int, int> A[M];
node B[M];
int ans[M];
int now[M];
bool cmp(node a, node b) { return a.val < b.val; }
bool check(int mid) {
  priority_queue<node> Q;
  memset(now, 0, sizeof(now));
  int r = n;
  long long cost = 0;
  for (int j = m; j >= 1; j -= mid) {
    while (r > 0 && B[r].val >= A[j].first) {
      Q.push(B[r--]);
    }
    if (Q.empty()) return 0;
    node t = Q.top();
    Q.pop();
    cost += t.cost;
    for (int k = j; k > max(0, j - mid); k--) {
      now[A[k].second] = t.id;
    }
  }
  return cost <= s;
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int j = 1; j <= m; j++) {
    scanf("%d", &A[j].first);
    A[j].second = j;
  }
  for (int j = 1; j <= n; j++) {
    scanf("%d", &B[j].val);
    B[j].id = j;
  }
  for (int j = 1; j <= n; j++) scanf("%d", &B[j].cost);
  sort(A + 1, A + 1 + m);
  sort(B + 1, B + 1 + n, cmp);
  int l = 0, r = INF;
  int res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      res = mid;
      for (int j = 1; j <= m; j++) {
        ans[j] = now[j];
      }
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (res) {
    printf("YES\n");
    for (int j = 1; j <= m; j++) printf("%d ", ans[j]);
    printf("\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
