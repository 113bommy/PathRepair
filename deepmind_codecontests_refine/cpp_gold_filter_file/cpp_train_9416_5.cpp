#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int n, m, w, a[maxn];
ll ft[maxn];
void upd(int pos, int val) {
  while (pos <= n) ft[pos] += val, pos += pos & (-pos);
}
ll get_prf(int pos) {
  ll ret = 0;
  while (pos > 0) ret += ft[pos], pos &= pos - 1;
  return ret;
}
bool can(int mid) {
  memset(ft, 0, sizeof(ll) * (n + 1));
  int moves = 0;
  for (int i = 1; i <= n; i++) {
    int diff = max(mid - int(a[i] + get_prf(i)), 0);
    moves += diff;
    upd(i, diff);
    upd(i + w, -diff);
    if (moves > m) return false;
  }
  return true;
}
int main() {
  scanf("%d %d %d", &n, &m, &w);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 1, r = 1e9 + 2e5;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (can(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}
