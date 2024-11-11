#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;
long long n, k, m;
vector<pair<long long, long long> > vec[MAXN];
long long cnt[MAXN << 2], sum[MAXN << 2];
void Build(int l, int r, int rt) {
  if (l == r) {
    cnt[rt] = sum[rt] = 0;
    return;
  }
  int m = (l + r) >> 1;
  Build(l, m, rt << 1);
  Build(m + 1, r, rt << 1 | 1);
}
void PushUp(int rt) {
  cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void Update(long long pos, long long val, int l, int r, int rt) {
  if (l == r) {
    cnt[rt] += val;
    sum[rt] += val * pos;
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m)
    Update(pos, val, l, m, rt << 1);
  else
    Update(pos, val, m + 1, r, rt << 1 | 1);
  PushUp(rt);
}
long long Query(int x, int l, int r, int rt) {
  if (cnt[rt] <= x) return sum[rt];
  if (l == r) return x * l;
  int m = (l + r) >> 1;
  if (cnt[rt << 1] >= x) return Query(x, l, m, rt << 1);
  return Query(cnt[rt << 1], l, m, rt << 1) +
         Query(x - cnt[rt << 1], m + 1, r, rt << 1 | 1);
}
int main() {
  scanf("%lld%lld%lld", &n, &k, &m);
  long long l, r, c, p, ans = 0, Max = 0;
  for (int i = 1; i <= m; ++i) {
    scanf("%lld%lld%lld%lld", &l, &r, &c, &p);
    Max = max(Max, p);
    vec[l].push_back(pair<long long, long long>(c, p));
    vec[r + 1].push_back(pair<long long, long long>(-1 * c, p));
  }
  Build(1, Max, 1);
  for (int i = 1; i <= n; ++i) {
    for (auto& v : vec[i]) Update(v.second, v.first, 1, Max, 1);
    ans += Query(k, 1, Max, 1);
  }
  printf("%lld\n", ans);
  return 0;
}
