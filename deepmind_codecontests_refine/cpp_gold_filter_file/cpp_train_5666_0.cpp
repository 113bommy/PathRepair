#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
pair<int, pair<int, int> > data[maxn], A[maxn];
int n, m, s;
int v[maxn], cost;
struct queNode {
  int num, cost, no;
  queNode() {}
  queNode(int num, int cost, int no) : num(num), cost(cost), no(no) {}
  bool operator<(const queNode& B) const {
    return cost > B.cost || (cost == B.cost && no > B.no);
  }
};
bool isok(int k) {
  cost = 0;
  priority_queue<queNode> que;
  int p = n;
  for (int i = m; i >= 1; i--) {
    while (p && data[p].first >= A[i].first) {
      que.push(queNode(k, data[p].second.first, data[p].second.second));
      p--;
    }
    if (que.empty()) return 0;
    queNode e = que.top();
    que.pop();
    cost += e.cost;
    e.cost = 0;
    e.num--;
    v[A[i].second.first] = e.no;
    if (e.num) que.push(e);
    if (cost > s) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= m; i++) scanf("%d", &A[i].first);
  for (int i = 1; i <= m; i++) A[i].second.first = i;
  for (int i = 1; i <= n; i++) scanf("%d", &data[i].first);
  for (int i = 1; i <= n; i++) scanf("%d", &data[i].second.first);
  for (int i = 1; i <= n; i++) data[i].second.second = i;
  sort(A + 1, A + 1 + m);
  sort(data + 1, data + 1 + n);
  if (!isok(m)) {
    cout << "NO" << endl;
    return 0;
  }
  int l = 1, r = m, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (isok(mid))
      r = mid;
    else
      l = mid + 1;
  }
  isok(l);
  cout << "YES" << endl;
  for (int i = 1; i <= m; i++) printf("%d ", v[i]);
  return 0;
}
