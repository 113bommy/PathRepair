#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, opsize, lim;
struct OP {
  int tim, d, tag, pos;
} op[N << 2];
inline bool oprule(OP x, OP y) {
  return (x.tim == y.tim) ? (x.tag < y.tag) : (x.tim < y.tim);
}
vector<int> lsh;
int p[N], s[N], b[N], c[N], f[N], ans[N];
int id(long long x) {
  return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin() + 1;
}
struct BIT {
  int w[N << 2];
  void mdf(int x, int d) {
    x = id(x);
    while (x <= lim) w[x] += d, x += (x & -x);
  }
  int qry(int x) {
    x = id(x);
    int res = 0;
    while (x) res += w[x], x -= (x & -x);
    return res;
  }
} bit[2];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &s[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    op[++opsize] = (OP){p[i], 1, 1, i};
    op[++opsize] = (OP){s[i] + 1, -1, 3, i};
  }
  for (int i = 1; i <= m; ++i) scanf("%d", &c[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &f[i]);
    op[++opsize] = (OP){c[i], 0, 2, i};
    lsh.push_back(c[i] + f[i]), lsh.push_back(c[i] - f[i]);
  }
  lsh.push_back(2e9), lsh.push_back(-2e9);
  sort(op + 1, op + opsize + 1, oprule);
  sort(lsh.begin(), lsh.end());
  unique(lsh.begin(), lsh.end()), lim = lsh.end() - lsh.begin() + 5;
  for (int i = 1, cnt = 0, pp; i <= opsize; ++i) {
    if (op[i].d)
      cnt += op[i].d, pp = op[i].pos, bit[0].mdf(p[pp] + b[pp], op[i].d),
                      bit[1].mdf(p[pp] - b[pp], op[i].d);
    else
      pp = op[i].pos,
      ans[pp] = bit[0].qry(c[pp] + f[pp]) + bit[1].qry(c[pp] - f[pp]) - cnt;
  }
  for (int i = 1; i <= m; ++i) printf("%d ", ans[i]);
  return 0;
}
