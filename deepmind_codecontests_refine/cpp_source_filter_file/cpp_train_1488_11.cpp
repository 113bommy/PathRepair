#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double pi = 2 * acos(0.0);
long long a1, a2, a3, b1, b2, b3, c, c1, c2, c3, d, d1, d2, d3, d4, d5, e1, e2,
    e3, f, h, k, l, m, n, m1, m2, n1, n2, o, p, p1, p2, p3, p4, q, q1, q2, q3,
    q4, r, s, t, u, v, x, y, z, sum, mx = -1e15, mn = 1e15, flg, flg1, flg2,
                                     id1, id2, id3, id4, lim, mx_id;
struct info {
  long long min_num, num_len;
  info(long long min_num_, long long num_len_) {
    min_num = min_num_;
    num_len = num_len_;
  }
};
long long A[2000001];
vector<long long> V[2000001];
vector<info> min_V;
bool cmp(info lf, info rt) {
  if (lf.num_len < rt.num_len)
    return true;
  else if (lf.num_len == rt.num_len) {
    if (lf.min_num < rt.min_num) return true;
  }
  return false;
}
void solve() {
  for (long long i = 0; i < n; i++) {
    V[A[i]].push_back(i + 1);
  }
  for (long long i = 1; i <= n; i++) {
    lim = V[i].size();
    if (lim) {
      c1 = 0;
      mx = 0;
      for (long long j = 0; j < lim; j++) {
        mx = max(mx, ((V[i][j] - c1)));
        c1 = V[i][j];
      }
      mx = max(mx, (n - c1) + 1);
      min_V.push_back(info(i, mx));
    }
  }
  sort(min_V.begin(), min_V.end(), cmp);
  c1 = min_V[0].min_num;
  c2 = min_V[0].num_len;
  id1 = 1;
  lim = min_V.size();
  for (long long i = 1; i <= n; i++) {
    if (i < c2)
      printf("-1 ");
    else {
      if (id1 < lim) {
        if (min_V[id1].num_len == i) {
          if (min_V[id1].min_num < c1) c1 = min_V[id1].min_num;
          id1++;
          while (id1 < lim && min_V[id1].num_len == i) id1++;
        }
      }
      printf("%I64d ", c1);
    }
  }
  printf("\n");
  for (long long i = 0; i < n; i++) {
    V[i].clear();
  }
  min_V.clear();
}
int main() {
  t = 1;
  scanf("%I64d", &t);
  while (t--) {
    scanf("%I64d", &n);
    for (long long i = 0; i < n; i++) {
      scanf("%I64d", &A[i]);
    }
    solve();
  }
  return 0;
}
