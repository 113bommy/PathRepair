#include <bits/stdc++.h>
using namespace std;
int n, k, avg, pre[200010], a[200010], lg2[200010], f[20][200010], g[200010];
int pos, res = INT_MAX;
map<int, int> lst[100010];
int get(int l, int r) {
  int res = 0;
  for (int i = l; i <= r; i++) res += a[i];
  return res;
}
void op(int l, int r, int lv) {
  vector<int> nw;
  a[r] = get(l, r) - lv - avg * (r - l - 1);
  a[l] = lv;
  for (int i = l + 1; i < r; i++) a[i] = avg;
  printf("%d ", (r - k + n) % n);
  for (int i = r - l + 1; i < k; i++) printf("%d ", a[pos - i + k - 1]);
  for (int i = l; i <= r; i++) printf("%d ", a[i]);
  puts("");
}
void work(int l, int r) {
  int w = get(max(r - k + 1, l), r);
  int i, tp;
  for (i = r - k + 1; i >= l && w / (r - i + 1) < avg;
       i -= k - 1, w += get(i, i + k - 2))
    ;
  tp = i;
  if (i < l) {
    if (i + k - 1 > l) op(l, i + k - 1, avg);
  } else
    op(i, i + k - 1, get(i, r) - avg * (r - i));
  for (i += k - 1; i < r; i += k - 1) op(i, i + k - 1, avg);
  if (l < tp) work(l, tp);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), avg += a[i], a[n + i] = a[i];
  assert(avg % n == 0), avg /= n;
  for (int i = 2; i <= 2 * n; i++) lg2[i] = lg2[i >> 1] + 1;
  for (int i = 1; i <= 2 * n; i++) {
    pre[i] = a[i] - avg + pre[i - 1];
    f[0][i] = lst[(i - 1) % (k - 1)][pre[i]];
    g[i] = f[0][i] ? g[f[0][i]] + (i - f[0][i] - 1) / (k - 1) : 0;
    for (int j = 1; f[j][i] = f[j - 1][f[j - 1][i]]; j++)
      ;
    lst[i % (k - 1)][pre[i]] = i;
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    int nw = i;
    for (int j = lg2[i]; j >= 0; j--)
      if (f[j][nw] >= i - n) nw = f[j][nw];
    int tmp = g[i] - g[nw], len = nw - (i - n);
    tmp += len ? (len <= k ? 1 : (len - 2) / (k - 1) + 1) : 0;
    if (tmp < res) res = tmp, pos = i;
  }
  printf("%d\n", res);
  for (int r = pos, l = pos - n + 1; r >= l; r = f[0][r]) {
    if (f[0][r] + 1 < r) work(max(l, f[0][r] + 1), r);
  }
}
