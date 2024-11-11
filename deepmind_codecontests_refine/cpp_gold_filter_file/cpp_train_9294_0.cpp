#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, S = 355;
int n, a[N], cnt[N], B, bel[N], cntb, L[N], R[N], mar[S][N];
vector<int> p[N];
pair<int, int> rg[N];
bool check(int l, int r, int mex) {
  if (!mex) return true;
  if (mex > n + 1) return false;
  for (int i = 1; i < bel[mex]; i++)
    if (mar[i][r] < l) return false;
  for (int i = L[bel[mex]], x; i <= mex; i++) {
    x = upper_bound(p[i].begin(), p[i].end(), r) - p[i].begin() - 1;
    if (p[i][x] < l) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]].push_back(i);
  for (int i = 1; i <= n; i++) p[i].push_back(0), p[i].push_back(n + 1);
  for (int i = 1; i <= n; i++) sort(p[i].begin(), p[i].end());
  B = sqrt(n);
  for (int i = 1; i <= n + 1; i++) bel[i] = (i - 1) / B + 1;
  cntb = bel[n];
  for (int i = 1; i <= cntb; i++) L[i] = (i - 1) * B + 1, R[i] = min(i * B, n);
  for (int k = 1, sl, sr; k <= cntb; k++) {
    sl = L[k];
    sr = R[k];
    for (int j = sl; j <= sr; j++) cnt[j] = 0;
    int now = 0;
    for (int j = 1, pos = 1; j <= n; j++) {
      if (a[j] >= sl && a[j] <= sr) {
        if (!cnt[a[j]]) now++;
        cnt[a[j]]++;
      }
      while (now == sr - sl + 1 &&
             (a[pos] < sl || a[pos] > sr || cnt[a[pos]] > 1)) {
        if (a[pos] >= sl && a[pos] <= sr) cnt[a[pos]]--;
        pos++;
      }
      if (now == sr - sl + 1)
        mar[k][j] = pos;
      else
        mar[k][j] = -1;
    }
  }
  for (int mex = 1, lst, len; mex <= n + 1; mex++) {
    len = lst = 0;
    for (auto x : p[mex]) {
      if (!x) {
        lst = x;
        continue;
      }
      if (lst + 1 < x) rg[++len] = pair<int, int>(lst + 1, x - 1);
      lst = x;
    }
    if (lst + 1 <= n) rg[++len] = pair<int, int>(lst + 1, n);
    bool fl = false;
    for (int i = 1; i <= len; i++)
      if (check(rg[i].first, rg[i].second, mex - 1)) {
        fl = true;
        break;
      }
    if (!fl) {
      printf("%d\n", mex);
      return 0;
    }
  }
  printf("%d\n", n + 2);
  return 0;
}
