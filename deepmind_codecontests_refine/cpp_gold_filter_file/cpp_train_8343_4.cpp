#include <bits/stdc++.h>
using namespace std;
struct node {
  int st, ed, val;
  friend bool operator<(const node &a, const node &b) { return a.ed > b.ed; }
} a[200010], tmp;
bool cmp(const node &a, const node &b) { return a.st < b.st; }
int cost[200010], n, m;
priority_queue<node> Q;
long long cmq;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &cost[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a[i].st, &a[i].ed, &a[i].val);
    a[i].st--;
    a[i].ed--;
    cmq += a[i].val;
  }
  sort(a, a + m, cmp);
  int j = 0;
  long long flow;
  for (int i = 0; i < n; i++) {
    for (; j < m && a[j].st == i; j++) Q.push(a[j]);
    flow = 0;
    while (!Q.empty() && flow < cost[i])
      if (Q.top().ed < i)
        Q.pop();
      else if (flow + Q.top().val >= cost[i]) {
        tmp = Q.top();
        Q.pop();
        tmp.val -= cost[i] - flow;
        Q.push(tmp);
        flow = cost[i];
      } else {
        flow += Q.top().val;
        Q.pop();
      }
    cmq -= flow;
  }
  cout << cmq << endl;
  return 0;
}
