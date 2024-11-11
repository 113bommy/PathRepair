#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005];
priority_queue<pair<int, int> > q;
pair<int, int> stk[(int)1e6 + 5];
int sz;
void doit(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
  int t = b.first / a.first;
  while (t) {
    if (t & 1)
      stk[sz++] = pair<int, int>(a.second, b.second), b.first -= a.first;
    else
      stk[sz++] = pair<int, int>(a.second, c.second), c.first -= a.first;
    a.first *= 2;
    t >>= 1;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i]) q.push(pair<int, int>(a[i], i));
  }
  if (q.size() == 1) {
    puts("-1");
    return 0;
  }
  while (q.size() > 2) {
    static pair<int, int> a, b, c;
    c = q.top(), q.pop();
    b = q.top(), q.pop();
    a = q.top(), q.pop();
    doit(a, b, c);
    if (a.first) q.push(a);
    if (b.first) q.push(b);
    if (c.first) q.push(c);
  }
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) printf("%d %d\n", stk[i].first, stk[i].second);
  return 0;
}
