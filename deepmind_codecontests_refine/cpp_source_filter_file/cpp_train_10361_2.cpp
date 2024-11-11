#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1061109567;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
long long v[100005], b[100005], sum[100005 * 4];
int id[100005];
void pushUp(int rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
void update(int p, long long val, int l, int r, int rt) {
  if (l == r) {
    sum[rt] += val;
    return;
  }
  int m = l + r >> 1;
  if (p <= m)
    update(p, val, l, m, rt << 1);
  else
    update(p, val, m + 1, r, rt << 1 | 1);
  pushUp(rt);
}
long long query(int L, int R, int l, int r, int rt) {
  if (R < L) return 0;
  if (L <= l && R >= r) {
    return sum[rt];
  }
  int m = l + r >> 1;
  long long ret = 0;
  if (L <= m) ret = query(L, R, l, m, rt << 1);
  if (R > m) ret = max(ret, query(L, R, m + 1, r, rt << 1 | 1));
  return ret;
}
int main() {
  int n, r, h;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &r, &h);
    v[i] = b[i] = 1LL * r * r * h;
  }
  sort(b, b + n);
  int num = unique(b, b + n) - b;
  for (int i = 0; i < n; i++) {
    id[i] = lower_bound(b, b + num, v[i]) - b + 1;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long tmp = query(1, id[i] - 1, 1, num, 1);
    update(id[i], tmp + v[i], 1, num, 1);
    ans = max(ans, tmp + v[i]);
  }
  printf("%.8f", ans * PI);
  return 0;
}
