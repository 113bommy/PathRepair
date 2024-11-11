#include <bits/stdc++.h>
const int MAXN = 505;
const int MAXM = 10005;
using namespace std;
int n, m, k, l, r;
pair<int, int> a[MAXN];
int fl[MAXM][MAXN], fr[MAXM][MAXN];
int find(int*, int);
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= n; i++) fl[0][i] = i;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) fl[i][j] = fl[i - 1][j];
    int pos1 = find(fl[i], a[i].first), pos2 = find(fl[i], a[i].second);
    if (pos1 != pos2) fl[i][pos2] = pos1;
  }
  for (int i = 1; i <= n; i++) fr[m + 1][i] = i;
  for (int i = m; i >= 1; i--) {
    for (int j = 1; j <= n; j++) fr[i][j] = fr[i + 1][j];
    int pos1 = find(fr[i], a[i].first), pos2 = find(fr[i], a[i].second);
    if (pos1 != pos2) fr[i][pos2] = pos1;
  }
  cin >> k;
  while (k--) {
    cin >> l >> r;
    int all[MAXN];
    memset(all, 0, sizeof(all));
    for (int i = 1; i <= n; i++) all[i] = fl[l - 1][i];
    for (int i = 1; i <= n; i++) {
      int pos1 = find(all, i), pos2 = find(all, fr[r + 1][i]);
      if (pos1 != pos2) all[pos2] = pos1;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
      if (find(all, i) == i) res++;
    cout << res << endl;
  }
  return 0;
}
int find(int* uf, int x) {
  if (uf[x] == x)
    return x;
  else {
    return uf[x] = find(uf, uf[x]);
  }
}
