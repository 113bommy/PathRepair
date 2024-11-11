#include <bits/stdc++.h>
const int N = 300;
const int INF = 1e9 + 9;
int n, m;
char a[N][N];
int c[N];
int b[N];
int cnt[N][26];
int d[2 * N];
bool check(int i, int j) {
  if (c[i] != c[j]) return false;
  if (i == j) return true;
  for (int k = 0; k < 26; k++) {
    if (cnt[i][k] != cnt[j][k]) return false;
  }
  return true;
}
int manaker() {
  d[0] = 1;
  int k = 2 * n - 1, mx = 1, id = 0, ans = b[0] >= 0;
  for (int i = 1; i < k; i++) {
    int i0 = i / 2, i1 = (i + 1) / 2;
    if (mx > i1)
      d[i] = std::min(mx - i1, d[2 * id - i]);
    else
      d[i] = 0;
    if (mx <= i1 || mx - i1 <= d[2 * id - i])
      while (i0 - d[i] >= 0 && i1 + d[i] < n && check(i0 - d[i], i1 + d[i])) {
        d[i]++;
      }
    if (i1 + d[i] > mx) {
      mx = i1 + d[i];
      id = i;
    }
    if (b[i1] >= 0) {
      ans += d[i];
    }
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf(" %s", a[i]);
  int ans = 0;
  for (int l = 0; l < m; l++) {
    std::fill(c, c + N, 0);
    memset(cnt, 0, sizeof cnt);
    for (int r = l; r < m; r++) {
      for (int i = 0; i < n; i++) {
        c[i] ^= (1 << (a[i][r] - 'a'));
        if ((c[i] & (c[i] - 1)) == 0)
          b[i] = c[i];
        else
          b[i] = -i - 1;
        cnt[i][a[i][r] - 'a']++;
      }
      int res = manaker();
      ans += res;
    }
  }
  printf("%d", ans);
}
