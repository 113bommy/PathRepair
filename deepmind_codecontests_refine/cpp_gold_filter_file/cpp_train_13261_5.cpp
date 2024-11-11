#include <bits/stdc++.h>
using namespace std;
const int max_n = 200010;
int n, m;
int a[max_n], ind[max_n];
vector<int> D[max_n];
int BIT[max_n + 1];
int bn;
void BITinit() { fill(BIT + 1, BIT + bn + 1, 0); }
void BITupd(int pos, int inc) {
  for (int i = pos; i <= bn; i += ((i) & (-i))) BIT[i] += inc;
}
int BITprs(int k) {
  int ret = 0;
  for (int i = k; i > 0; i -= ((i) & (-i))) ret += BIT[i];
  return ret;
}
int BITqry(int l, int r) { return BITprs(r) - BITprs(l - 1); }
struct P {
  int IN, l, r;
  P() {}
  P(int IN_, int l_, int r_) {
    IN = IN_;
    l = l_;
    r = r_;
  }
};
struct less_P_r : public binary_function<P, P, bool> {
  bool operator()(const P &a, const P &b) {
    return (a.r < b.r or (a.r == b.r and a.l < b.l));
  }
};
P interval[max_n];
int res[max_n];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ind[a[i]] = i;
  }
  int x, y;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    interval[i] = P(i, x, y);
  }
  sort(interval, interval + m, less_P_r());
  for (int i = 1; i <= n; i++)
    for (int j = 2 * i; j <= n; j += i) D[j].push_back(i);
  int cnt = 0;
  bn = n;
  for (int i = 1; i <= n; i++) {
    int k = a[i];
    for (int j = k; j <= n; j += k)
      if (ind[j] <= i) BITupd(ind[j], 1);
    for (int j = 0; j < D[k].size(); j++)
      if (ind[D[k][j]] <= i) BITupd(ind[D[k][j]], 1);
    while (interval[cnt].r == i) {
      res[interval[cnt].IN] = BITqry(interval[cnt].l, i);
      cnt++;
    }
  }
  for (int i = 0; i < m; i++) printf("%d\n", res[i]);
  return 0;
}
