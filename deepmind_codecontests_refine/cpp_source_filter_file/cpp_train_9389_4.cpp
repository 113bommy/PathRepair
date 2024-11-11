#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
char s[N];
long long n, t[N], rnk[N], cnt[N], tmp[N], rnk1[N], k, sa[N], h[N], l[N][2],
    top, len[N];
long long ans;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) t[s[i]] = 1;
  for (int i = 1; i <= N; i++) t[i] += t[i - 1];
  for (int i = 1; i <= n; i++) rnk[i] = t[s[i]];
  for (int p = 1; p <= n; p *= 2) {
    if (k == n) break;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) cnt[rnk[i + p]]++;
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) tmp[cnt[rnk[i + p]]--] = i;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) cnt[rnk[i]]++;
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rnk[tmp[i]]]--] = tmp[i];
    memcpy(rnk1, rnk, sizeof rnk);
    k = 1;
    rnk[sa[1]] = 1;
    for (int i = 2; i <= n; i++) {
      if (rnk1[sa[i]] != rnk1[sa[i - 1]] ||
          rnk1[sa[i] + p] != rnk1[sa[i - 1] + p])
        k++;
      rnk[sa[i]] = k;
    }
  }
  k = 0;
  for (int i = 1; i <= n; i++) {
    if (rnk[i] == n) h[rnk[i]] = 0;
    k = max(k - 1, (long long)0);
    while (s[sa[rnk[i] + 1] + k] == s[i + k]) k++;
    h[rnk[i]] = k;
  }
  for (int i = 1; i <= n; i++) len[i] = n - sa[i] + 1;
  for (int i = 1; i <= n; i++) {
    ans += len[i] - max(h[i], h[i - 1]);
    if (h[i] < l[top][0] && top > 0) {
      while (h[i] < l[top][0]) {
        if (l[top - 1][0] != l[top][0]) {
          ans += (l[top][0] - max(l[top - 1][0], h[i])) * (i - l[top - 1][1]) *
                 (i - l[top - 1][1] + 1) / 2;
        }
        top--;
      }
    }
    l[++top][0] = h[i];
    l[top][1] = i;
  }
  printf("%d", ans);
  return 0;
}
