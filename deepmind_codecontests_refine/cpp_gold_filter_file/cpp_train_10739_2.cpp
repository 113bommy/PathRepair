#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int lpos[505], rpos[505];
int minn[2005][2005], minl[2005][2005], maxr[2005][2005];
bool vis[2005][2005], can[2005][2005];
int f[2005][2005];
int dp(int l, int r) {
  if (l > r) return 1;
  if (!can[l][r]) return 0;
  if (vis[l][r]) return f[l][r];
  vis[l][r] = 1;
  int x = minn[l][r], nl = lpos[x], nr = rpos[x];
  long long s1 = 0, s2 = 0;
  for (int i = nl; i >= l; i--)
    s1 = (s1 + (long long)dp(l, i - 1) * dp(i, nl - 1)) % 998244353;
  for (int i = nr; i <= r; i++)
    s2 = (s2 + (long long)dp(i + 1, r) * dp(nr + 1, i)) % 998244353;
  long long s = s1 * s2 % 998244353;
  for (int i = nl + 1, last2 = nl; i <= nr; i++)
    if (a[i] == x) {
      s = s * dp(last2 + 1, i - 1) % 998244353;
      last2 = i;
    }
  return f[l][r] = s;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    if (i == 1 || x != a[cnt]) {
      a[++cnt] = x;
      if (!lpos[x]) lpos[x] = cnt;
      rpos[x] = cnt;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      if ((lpos[j] > lpos[i] && lpos[j] < rpos[i]) ||
          (rpos[j] > lpos[i] && rpos[j] < rpos[i])) {
        puts("0");
        return 0;
      }
  if (cnt > 1100) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= cnt; i++) {
    minn[i][i] = a[i];
    minl[i][i] = lpos[a[i]];
    maxr[i][i] = rpos[a[i]];
    for (int j = i + 1; j <= cnt; j++) {
      minn[i][j] = min(minn[i][j - 1], a[j]);
      minl[i][j] = min(minl[i][j - 1], lpos[a[j]]);
      maxr[i][j] = max(maxr[i][j - 1], rpos[a[j]]);
    }
  }
  for (int i = 1; i <= cnt; i++)
    for (int j = i; j <= cnt; j++)
      can[i][j] = (minl[i][j] >= i && maxr[i][j] <= j);
  printf("%d\n", dp(1, cnt));
  return 0;
}
