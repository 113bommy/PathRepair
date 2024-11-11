#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 300005;
struct Node {
  int l, r, id;
  bool operator<(const Node &b) const { return l < b.l; }
} a[N];
int n, k, ans, ansl, ansr;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; ++i) a[i].l = read(), a[i].r = read(), a[i].id = i;
  sort(a + 1, a + n + 1);
  for (int i = 1, cur; i <= n; ++i) {
    q.push(a[i].r);
    if (q.size() > k) q.pop();
    if (q.size() == k)
      cur = q.top() - a[i].l + 1;
    else
      cur = 0;
    if (cur > ans) ansl = a[i].l, ansr = q.top(), ans = cur;
  }
  printf("%d\n", ans);
  if (!ans) {
    for (int i = 1; i < k; ++i) printf("%d ", a[i].id);
    printf("%d\n", a[k].id);
    return 0;
  }
  for (int i = 1, cnt = k; i <= n; ++i)
    if (a[i].l <= ansl && a[i].r >= ansr)
      if (cnt != 1)
        printf("%d ", a[i].id), --cnt;
      else if (cnt == 1)
        printf("%d", a[i].id), --cnt;
      else
        break;
  puts("");
  return 0;
}
