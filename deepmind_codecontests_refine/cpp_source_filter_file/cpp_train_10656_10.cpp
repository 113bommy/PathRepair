#include <bits/stdc++.h>
using namespace std;
struct est {
  int l, r, id;
  est(){};
  est(int a, int b, int c) {
    l = a;
    r = b;
    id = c;
  }
  bool operator<(est t) const {
    if (l != t.l)
      return l < t.l;
    else if (r != t.r)
      return r > t.r;
    else
      return id < t.id;
  }
};
vector<est> v;
vector<est> r;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int ll, rr;
    scanf("%d %d", &ll, &rr);
    v.push_back(est(ll, rr, i + 1));
    r.push_back(est(rr, ll, (i + 1)));
  }
  sort(v.begin(), v.end());
  sort(r.rbegin(), r.rend());
  if (v[0].r >= r[0].r)
    printf("%d\n", v[0].id);
  else
    printf("-1\n");
  return 0;
}
