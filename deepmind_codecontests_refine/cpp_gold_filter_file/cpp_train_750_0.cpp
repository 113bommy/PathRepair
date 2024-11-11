#include <bits/stdc++.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    static char cc[200000 + 1];
    static int kk[26], kk_[200000 + 1], qu[200000 + 1], ll[200000 + 1];
    int n, m, h, i, k, a, cnt, ans;
    scanf("%s", cc), n = strlen(cc);
    memset(kk, 0, sizeof kk);
    for (i = 1; i < n; i++)
      if (cc[i] == cc[i - 1]) kk[cc[i] - 'a']++;
    memset(kk_, 0, (n + 1) * sizeof *kk_);
    m = 0, k = 0;
    for (a = 0; a < 26; a++) {
      kk_[kk[a]]++;
      m += kk[a], k = max(k, kk[a]);
    }
    m = (m + 1) / 2;
    ans = max(m, k) + 1;
    memset(ll, -1, (n + 1) * sizeof *ll);
    cnt = 0;
    for (i = 1; i < n && k < m; i++)
      if (cc[i] == cc[i - 1]) {
        if (cnt && cc[qu[cnt - 1]] != cc[i]) {
          ll[i] = qu[--cnt];
          a = cc[ll[i]] - 'a', kk_[kk[a]]--, kk[a]--, kk_[kk[a]]++;
          a = cc[i] - 'a', kk_[kk[a]]--, kk[a]--, kk_[kk[a]]++;
          if (kk_[k] == 0) k--;
          m--;
        } else
          qu[cnt++] = i;
      }
    for (a = 0; a < 26; a++)
      if (kk[a] >= m) break;
    for (; i < n; i++)
      if (cc[i] == cc[i - 1]) {
        if (cnt && (cc[qu[cnt - 1]] == a + 'a') != (cc[i] == a + 'a'))
          ll[i] = qu[--cnt];
        else
          qu[cnt++] = i;
      }
    i = 0;
    for (h = 0; h < cnt; h++) ll[qu[h]] = i, i = qu[h];
    ll[n] = i;
    cnt = 0;
    printf("%d\n", ans);
    for (i = 0; i <= n; i++) {
      if (ll[i] != -1) {
        int l, r;
        r = cnt;
        while (cnt && qu[cnt - 1] >= ll[i]) cnt--;
        l = cnt + 1;
        printf("%d %d\n", l, r);
      }
      qu[cnt++] = i;
    }
  }
  return 0;
}
