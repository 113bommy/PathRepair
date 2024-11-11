#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, m;
long long v[maxn];
long long tmp[maxn];
map<long long, int> id;
long long segt[maxn << 2];
long long dp[maxn];
const bool cmp(const int& a, const int& b) { return v[a] < v[b]; }
long long query(int rt, int L, int R, int l, int r) {
  if (l <= L && r >= R) return segt[rt];
  if (L + 1 == R) return segt[rt];
  int m = (L + R) >> 1;
  long long v1, v2;
  v1 = v2 = 0;
  if (m > l) v1 = query(rt << 1, L, m, l, r);
  if (m < r) v2 = query(rt << 1 | 1, m, R, l, r);
  return max(v1, v2);
}
void update(int rt, int L, int R, int idd, long long key) {
  if (L + 1 == R)
    segt[rt] = key;
  else {
    int m = (L + R) >> 1;
    int lc = rt << 1, rc = rt << 1 | 1;
    if (m > idd)
      update(rt << 1, L, m, idd, key);
    else
      update(rt << 1 | 1, m, R, idd, key);
    segt[rt] = max(segt[rc], segt[lc]);
  }
}
long long solve() {
  long long ans = 0;
  for (int i = 0; i < int(n); i++) {
    long long t = query(1, 0, m, 0, id[v[i]]) + v[i];
    update(1, 0, m, id[v[i]], t);
    ans = max(t, ans);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < int(n); i++) {
    int r, h;
    scanf("%d%d", &r, &h);
    v[i] = (long long)r * r * h;
    tmp[i] = i;
  }
  sort(tmp, tmp + n, cmp);
  m = unique(tmp, tmp + n) - tmp;
  for (int i = 0; i < int(m); i++) id[v[tmp[i]]] = i;
  printf("%.12lf\n", 1.0 * solve() * acos(-1));
  return 0;
}
