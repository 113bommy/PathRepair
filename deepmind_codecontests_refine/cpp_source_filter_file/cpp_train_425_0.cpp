#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
vector<pair<int, pair<long long, long long>>> e;
vector<int> cmp;
unordered_map<int, int> ord;
long long bit[N], bit1[N], cst[N];
long long query(int i, long long tree[]) {
  long long res = 0;
  for (++i; i > 0; i -= i & -i) res += tree[i];
  return res;
}
void upd(int i, long long v, long long tree[]) {
  for (++i; i < N; i += i & -i) tree[i] += v;
}
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < m; ++i) {
    int l, r, c, p;
    scanf("%d%d%d%d", &l, &r, &c, &p);
    e.push_back({l, {c, p}});
    e.push_back({r + 1, {-c, p}});
    cmp.push_back(p);
  }
  sort(e.begin(), e.end());
  sort(cmp.begin(), cmp.end());
  for (int i = 0, j = 0; i < n; ++i)
    if (ord.count(cmp[i]) == 0) cst[j] = cmp[i], ord.insert({cmp[i], j++});
  long long ans = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    for (; e[j].first == i; ++j) {
      int idx = ord[e[j].second.second];
      upd(idx, e[j].second.first, bit);
      upd(idx, e[j].second.second * e[j].second.first, bit1);
    }
    if (query(N - 2, bit) <= k) {
      ans += query(N - 2, bit1);
      continue;
    }
    int l = 0, h = n;
    while (l < h) {
      int m = (l + h) / 2;
      if (query(m, bit) <= k)
        l = m + 1;
      else
        h = m;
    }
    long long rem = k - query(l - 1, bit);
    ans += query(l - 1, bit1) + rem * cst[l];
  }
  printf("%lld\n", ans);
  return 0;
}
