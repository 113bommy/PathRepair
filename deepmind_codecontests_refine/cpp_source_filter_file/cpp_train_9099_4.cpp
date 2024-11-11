#include <bits/stdc++.h>
using namespace std;
int nxt(int a, int b) {
  int tmp = a;
  if (b) tmp++;
  int r = 0, t = 1;
  while (t < tmp) t <<= 1, r++;
  return a + r;
}
struct S {
  int a, b, c;
};
vector<S> a[7010];
int n, m;
int solve(int t, int v) {
  int l = v, r = v;
  set<int> res;
  for (int i = t; i <= n; ++i) {
    for (int j = 0; j < a[i].size(); ++j) {
      S &s = a[i][j];
      if (s.a <= l && s.b >= l)
        res.insert(s.c);
      else if (l <= s.a && r >= s.b)
        res.insert(s.c);
    }
    l = nxt(l, 0);
    r = nxt(r, 1);
  }
  return res.size();
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int o;
    scanf("%d", &o);
    if (o == 1) {
      int t, l, r, x;
      scanf("%d%d", &t, &l);
      scanf("%d%d", &r, &x);
      a[t].push_back((S){l, r, x});
    } else {
      int t, v;
      scanf("%d%d", &t, &v);
      printf("%d\n", solve(t, v));
    }
  }
  return 0;
}
