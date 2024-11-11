#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct base {
  static vector<int> pow2;
  int d[22 + 1] = {}, p[22 + 1] = {};
  int sz = 0, cnt = 0, ins = 0;
  bool insert(int x) {
    if (pow2.size() <= ++ins) pow2.push_back((pow2.back() << 1) % mod);
    for (int i = 22; ~i; i--)
      if ((x >> i) & 1) {
        if (!d[i]) {
          cnt++, d[i] = x;
          break;
        }
        x ^= d[i];
      }
    if (x) p[sz++] = x;
    return x;
  }
  int max() {
    int ret = 0;
    for (int i = 22; ~i; i--)
      if ((ret ^ d[i]) > ret) ret ^= d[i];
    return ret;
  }
  int min() {
    for (int i = 0; i <= 22; i++)
      if (d[i]) return d[i];
    return 0;
  }
  int count(int x) {
    for (int i = 22; ~i; i--)
      if ((x >> i) & 1) x ^= d[i];
    return x ? 0 : pow2[ins - sz];
  }
};
vector<int> base::pow2{1};
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n);
  for (int& i : a) scanf("%d", &i);
  vector<pair<int, int>> qs[n];
  for (int l, x, i = 0; i < q; i++) {
    scanf("%d%d", &l, &x);
    qs[l - 1].push_back({x, i});
  }
  base b;
  vector<int> ans(q);
  for (int i = 0; i < n; i++) {
    b.insert(a[i]);
    for (auto& p : qs[i]) ans[p.second] = b.count(p.first);
  }
  for (int& a : ans) printf("%d\n", a);
}
