#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> a;
set<int> c;
int p[100005], q[100005], d[3] = {-1, 0, 1};
bool v[100005];
bool judge(int x) {
  int i, j, s;
  for (i = 0; i < 3; i++) {
    int t1, t2, w;
    t1 = p[x] + d[i];
    t2 = q[x] + 1;
    w = a[make_pair(t1, t2)];
    if (w && !v[w]) {
      s = 0;
      for (j = 0; j < 3; j++) {
        int t1, t2, w;
        t1 = t1 + d[j];
        t2 = q[x];
        w = a[make_pair(t1, t2)];
        if (w && !v[w]) s++;
      }
      if (s == 1) return false;
    }
  }
  return true;
}
int main() {
  long long ans = 0;
  int n, i;
  bool f = false;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &p[i], &q[i]);
    a[make_pair(p[i], q[i])] = i;
  }
  for (i = 1; i <= n; i++) {
    if (judge(i)) c.insert(i);
  }
  while (c.size()) {
    int x;
    if (f)
      x = *c.begin();
    else
      x = *c.rbegin();
    c.erase(x);
    if (!judge(x)) continue;
    f = !f;
    v[x] = true;
    ans = (ans * n + x - 1) % 1000000009;
    ;
    for (i = 0; i < 3; i++) {
      int t1, t2, w;
      t1 = p[x] + d[i];
      t2 = q[x] - 1;
      w = a[make_pair(t1, t2)];
      if (w && !v[w] && judge(w)) c.insert(w);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
