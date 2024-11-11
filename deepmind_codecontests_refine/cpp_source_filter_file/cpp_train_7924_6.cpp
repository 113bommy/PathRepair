#include <bits/stdc++.h>
const int N = 2e3 + 9;
const int inf = 1e9 + 1;
using namespace std;
using ll = long long;
int num[N], cnt, pl, pr, vl, vr, k;
ll ans = 0;
void dfs(ll s) {
  if (s > 1e9) return;
  if (s) num[cnt++] = s;
  dfs(s * 10 + 4);
  dfs(s * 10 + 7);
}
ll slove(int L, int l, int r, int R) {
  ll res = 0;
  res += 1LL * max(min(pr, l) - max(pl, L + 1) + 1, 0) *
         max(min(R - 1, vr) - max(vl, r) + 1, 0);
  res += 1LL * max(min(vr, l) - max(vl, L + 1) + 1, 0) *
         max(min(R - 1, pr) - max(pl, r) + 1, 0);
  if (l == r && max(pl, vl) <= l && l <= min(pr, vr)) res++;
  return res;
}
int main() {
  dfs(0);
  sort(num, num + cnt);
  scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k);
  for (int i = 0; i < cnt - k && max(vr, pr) >= num[i + k - 1]; i++) {
    ans += slove(i > 0 ? num[i - 1] : 0, num[i], num[i + k - 1],
                 (i + k) < cnt ? num[i + k] : inf);
  }
  return printf("%.12f\n", 1.0 * ans / (pr - pl + 1) / (vr - vl + 1)), 0;
}
