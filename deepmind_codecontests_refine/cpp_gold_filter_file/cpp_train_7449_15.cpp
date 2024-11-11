#include <bits/stdc++.h>
using namespace std;
long long Abs(long long x) {
  if (x < 0) return -x;
  return x;
}
struct node {
  long long x;
  int i;
  bool operator<(const node &a) const { return Abs(x) > Abs(a.x); }
} a[200100];
int main() {
  int n, k;
  long long x;
  scanf("%d%d%I64d", &n, &k, &x);
  long long mi = 10000000000ll;
  int mark = 0, flag = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i].x), a[i].i = i;
    if (a[i].x < 0) flag++;
    if (mi > Abs(a[i].x)) mi = Abs(a[i].x), mark = i;
  }
  if (flag % 2 == 0) {
    if (a[mark].x < 0)
      while (a[mark].x < 0 && k) a[mark].x += x, k--;
    else if (a[mark].x >= 0)
      while (a[mark].x >= 0 && k) a[mark].x -= x, k--;
  }
  priority_queue<node> q;
  for (int i = 1; i <= n; i++) q.push(a[i]);
  while (k) {
    node e = q.top();
    q.pop();
    if (e.x < 0)
      e.x -= x;
    else
      e.x += x;
    q.push(e);
    k--;
  }
  while (q.size()) {
    node e = q.top();
    q.pop();
    a[e.i].x = e.x;
  }
  for (int i = 1; i < n; i++) cout << a[i].x << " ";
  cout << a[n].x << endl;
  return 0;
}
