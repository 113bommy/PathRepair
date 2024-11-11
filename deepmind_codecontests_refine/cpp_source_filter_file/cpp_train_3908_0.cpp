#include <bits/stdc++.h>
using namespace std;
int n, bit[22], Log[500100], sum[500100], x[500100], y[500100], c[500100],
    sa[500100], rk[500100], hei[500100], mmin[500100 * 2][22];
char ch[500100];
long long ans;
vector<int> v[500100 * 2];
void suf_sort(char *a, int n, int m = 3) {
  for (int i = 1; i <= m; i++) c[i] = 0;
  for (int i = 1; i <= n; i++) x[i] = a[i] - 'a' + 1;
  for (int i = 1; i <= n; i++) c[x[i]]++;
  for (int i = 1; i <= m; i++) c[i] += c[i - 1];
  for (int i = 1; i <= n; i++) sa[c[x[i]]--] = i;
  for (int len = 1; len <= n; len <<= 1) {
    int num = 0;
    for (int i = n - len + 1; i <= n; i++) y[++num] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > len) y[++num] = sa[i] - len;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[x[i]]++;
    for (int i = 1; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[x[y[i]]]--] = y[i];
    for (int i = 1; i <= n; i++) y[i] = x[i], x[i] = 0;
    x[sa[1]] = m = 1;
    for (int i = 2; i <= n; i++)
      x[sa[i]] =
          (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + len] == y[sa[i - 1] + len])
              ? m
              : ++m;
    if (n == m) break;
  }
  for (int i = 1; i <= n; i++) rk[sa[i]] = i;
  for (int i = 1, k = 0; i <= n; hei[rk[i++]] = k, k = max(0, k - 1))
    while (a[i + k] == a[sa[rk[i] - 1] + k]) k++;
}
int query(int l, int r) {
  int k = Log[r - l + 1];
  return min(mmin[l][k], mmin[r - bit[k] + 1][k]);
}
int main() {
  scanf("%d%s", &n, ch + 1);
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i - 1] + (ch[i] == '(' ? 1 : -1),
    v[sum[i] + 500000].push_back(i);
  for (int i = 1; i <= n; i++) ch[i] = (ch[i] == '(' ? 'a' : 'b');
  suf_sort(ch, n);
  bit[0] = 1;
  for (int i = 1; i <= 20; i++) bit[i] = bit[i - 1] * 2;
  for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  for (int i = 1; i <= n; i++) mmin[i][0] = sum[i];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++)
      mmin[i][j] = min(mmin[i][j - 1], mmin[i + bit[j - 1]][j - 1]);
  for (int i = 1; i <= n; i++) {
    if (ch[i] == 'b') continue;
    int now = sum[i - 1] + 500000,
        l = lower_bound(v[now].begin(), v[now].end(), i + hei[rk[i]]) -
            v[now].begin(),
        r = v[now].size() - 1, L = l, ret = L - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (query(i, v[now][mid]) >= sum[i - 1])
        ret = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    ans += ret - L + 1;
  }
  printf("%d\n", ans);
}
