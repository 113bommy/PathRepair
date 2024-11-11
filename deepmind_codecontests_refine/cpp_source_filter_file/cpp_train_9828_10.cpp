#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  char c;
  bool flag = false;
  c = getchar();
  while (!isdigit(c)) {
    flag = (c == '-');
    c = getchar();
  }
  while (isdigit(c)) {
    res = res * 10 + (c ^ 48);
    c = getchar();
  }
  return !flag ? res : -res;
}
const int Max_n = 5e5 + 5;
struct node {
  int val, num;
  node(int a, int b) { val = a, num = b; }
  node() {}
} piz[Max_n];
priority_queue<int, vector<int>, greater<int> > q;
int n, a[Max_n], tot, pre[Max_n], st[Max_n], tp;
long long ans;
inline bool cmp(int a, int b) { return a > b; }
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), ans += a[i];
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[i - 1])
      ++piz[tot].num;
    else
      piz[++tot] = node(a[i], 1);
  }
  for (int i = 1; i <= tot; ++i) pre[i] = pre[i - 1] + piz[i].num;
  for (int i = 1; i <= tot; ++i) {
    int rem = pre[i - 1] - 2 * q.size();
    rem = min(rem, piz[i].num);
    for (int j = 1; j <= rem; ++j) st[++tp] = piz[i].val;
    rem = min(pre[i - 1], piz[i].num) - rem;
    for (int j = 1; j <= rem; j += 2) {
      int now = q.top();
      q.pop();
      if (now < piz[i].val) {
        st[++tp] = piz[i].val;
        if (j != rem) st[++tp] = piz[i].num;
      } else {
        st[++tp] = now;
        if (j != rem && 2 * piz[i].val > now) st[++tp] = 2 * piz[i].val - now;
      }
    }
    while (tp) q.push(st[tp]), --tp;
  }
  while (!q.empty()) {
    ans -= q.top();
    q.pop();
  }
  printf("%lld\n", ans);
  return 0;
}
