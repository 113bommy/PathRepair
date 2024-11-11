#include <bits/stdc++.h>
using namespace std;
const int N(100010), L(17), P(53);
int n;
long long sc[N][26];
int glen[L + 1];
bool gray[L + 1][N];
int cnt[N][26];
long long cut[N];
long long ha[N], p[N];
char s[N];
bool same(int x, int y, int len) {
  if (x > y) swap(x, y);
  long long h1 = ha[x + len - 1] - ha[x - 1], h2 = ha[y + len - 1] - ha[y - 1];
  return h1 * p[y - x] == h2;
}
int lcp(int x, int y) {
  int ret = 0;
  for (int i = L; i != -1; --i)
    if (x + (1 << i) - 1 <= n && y + (1 << i) - 1 <= n && same(x, y, 1 << i)) {
      x += 1 << i;
      y += 1 << i;
      ret += 1 << i;
    }
  return ret;
}
int lcs(int x, int y) {
  int ret = 0;
  for (int i = L; i != -1; --i)
    if (x - (1 << i) + 1 > 0 && y - (1 << i) + 1 > 0 &&
        same(x - (1 << i) + 1, y - (1 << i) + 1, 1 << i)) {
      x -= 1 << i;
      y -= 1 << i;
      ret += 1 << i;
    }
  return ret;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] * P;
    ha[i] = ha[i - 1] + p[i] * (s[i] - 'a' + 1);
    memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i - 1]));
    ++cnt[i][s[i] - 'a'];
    gray[1][i] = true;
  }
  for (int i = 1; i <= L; ++i) glen[i] = glen[i - 1] * 2 + 1;
  long long ans = n;
  for (int i = 2; i <= L; ++i) {
    for (int j = 1; j + glen[i] - 1 <= n; ++j) {
      int l = j, mid = j + glen[i - 1], r = j + glen[i] - 1, c = s[mid] - 'a';
      gray[i][j] = gray[i - 1][l] && gray[i - 1][mid + 1] &&
                   cnt[r][c] - cnt[l - 1][c] == 1 &&
                   same(l, mid + 1, glen[i - 1]);
      if (gray[i][j]) {
        long long tmp = (long long)glen[i] * glen[i];
        ans += tmp;
        cut[l] += tmp;
        cut[r + 1] -= tmp;
      }
    }
  }
  ++cut[0];
  for (int i = 1; i <= n; ++i) cut[i] += cut[i - 1];
  for (int i = 1; i <= L; ++i) {
    if (i == 1) {
      for (int j = int(1); j < int(n + 1); ++j)
        for (int k = int(0); k < int(26); ++k) ++sc[j][k];
      continue;
    }
    for (int j = glen[i - 1] + 1; j + glen[i - 1] <= n; ++j) {
      int l = j - glen[i - 1], mid = j, r = j + glen[i - 1];
      if (gray[i - 1][l] && gray[i - 1][mid + 1] &&
          same(l, mid + 1, glen[i - 1])) {
        for (int k = 0; k != 26; ++k)
          if (cnt[r][k] - cnt[l - 1][k] == 0)
            sc[j][k] += (long long)glen[i] * glen[i];
      }
      int len1 = lcp(l, mid + 1), len2 = lcs(mid - 1, r), c = s[mid] - 'a';
      if (len1 + len2 == glen[i - 1] - 1 && gray[i - 1][mid + 1]) {
        int p = l + len1, q = s[mid + 1 + len1] - 'a';
        if (cnt[r][c] - cnt[l - 1][c] == 1 + (c == s[p] - 'a'))
          sc[p][q] += (long long)glen[i] * glen[i];
      }
      if (len1 + len2 == glen[i - 1] - 1 && gray[i - 1][l]) {
        int p = mid + 1 + len1, q = s[l + len1] - 'a';
        if (cnt[r][c] - cnt[l - 1][c] == 1 + (c == s[p] - 'a'))
          sc[p][q] += (long long)glen[i] * glen[i];
      }
    }
  }
  long long del = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j != 26; ++j)
      if (s[i] != j + 'a') del = max(del, sc[i][j] - cut[i]);
  cout << ans + del << endl;
  return 0;
}
