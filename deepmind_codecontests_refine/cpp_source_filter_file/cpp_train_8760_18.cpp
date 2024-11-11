#include <bits/stdc++.h>
using namespace std;
int n, m, p;
long long x[1000005], s[1000005], ans;
vector<long long> v[4000005];
void build(int l, int r, int i) {
  if (l + 1 == r) {
    v[i].push_back(p - x[l]);
    return;
  }
  int mi = (l + r) / 2;
  build(l, mi, i * 2);
  build(mi, r, i * 2 + 1);
  long long sum = s[mi] - s[l];
  for (int j = 0; j <= v[i * 2].size(); j++) {
    while (1) {
      int nxt = v[i].size() + 1 - j;
      if (nxt == 0) {
        assert(j);
        v[i].push_back(v[i * 2][j - 1]);
        continue;
      }
      assert(nxt > 0);
      if (nxt > v[i * 2 + 1].size()) break;
      long long add = sum - j * p;
      long long threshold = v[i * 2 + 1][nxt - 1] - add;
      if (j) threshold = max(v[i * 2][j - 1], threshold);
      if (j != v[i * 2].size() && threshold >= v[i * 2][j]) break;
      v[i].push_back(threshold);
    }
  }
}
void query(int a, int b, int l, int r, int i) {
  if (a == l && b == r) {
    ans -= (upper_bound(v[i].begin(), v[i].end(), ans) - v[i].begin()) * p;
    ans += s[r] - s[l];
    return;
  }
  int mi = (l + r) / 2;
  if (a < mi) query(a, min(mi, b), l, mi, i * 2);
  if (mi < b) query(max(mi, a), b, mi, r, i * 2 + 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 0; i < n; i++) {
    scanf("%lld", x + i);
    s[i + 1] = s[i] + x[i];
  }
  build(0, n, 1);
  while (m--) {
    int l, r;
    ans = 0;
    scanf("%d%d", &l, &r);
    query(l - 1, r, 0, n, 1);
    printf("%lld\n", ans);
  }
}
