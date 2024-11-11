#include <bits/stdc++.h>
using namespace std;
char s[500005], t[500005];
int n, m, k, nxt[100005], a[100005], b[100005];
int main() {
  memset(a, 61, sizeof a);
  memset(b, 63, sizeof b);
  scanf("%d%d%d%s%s", &n, &m, &k, s + 1, t + 1);
  for (int i = 2, j = 0; i <= m && i <= k; i++) {
    while (j && t[j + 1] != t[i]) j = nxt[j];
    if (t[j + 1] == t[i]) j++;
    nxt[i] = j;
  }
  for (int i = 1, j = 0; i <= n; i++) {
    while (j && (j == k || t[j + 1] != s[i])) j = nxt[j];
    if (t[j + 1] == s[i]) j++;
    if (j == m) {
      if (i < k * 2) {
        printf("Yes\n1 %d\n", k + 1);
      } else {
        printf("Yes\n%d %d\n", i - k * 2 + 1, i - k + 1);
      }
      return 0;
    }
    if (i - k > -1) a[j] = min(a[j], i);
  }
  for (int i = m; i > 0; i--) {
    a[nxt[i]] = min(a[nxt[i]], a[i]);
  }
  reverse(s + 1, s + n + 1);
  reverse(t + 1, t + m + 1);
  for (int i = 2, j = 0; i <= m && i <= k; i++) {
    while (j && t[j + 1] != t[i]) j = nxt[j];
    if (t[j + 1] == t[i]) j++;
    nxt[i] = j;
  }
  for (int i = 1, j = 0; i <= n; i++) {
    while (j && (j == k || t[j + 1] != s[i])) j = nxt[j];
    if (t[j + 1] == s[i]) j++;
    if (j == m) {
      if (i < k * 2) {
        printf("Yes\n1 %d\n", k + 1);
      } else {
        printf("Yes\n%d %d\n", i - k * 2 + 1, i - k + 1);
      }
      return 0;
    }
    if (i - k > -1) b[j] = min(b[j], i);
  }
  for (int i = m; i > 0; i--) {
    b[nxt[i]] = min(b[nxt[i]], b[i]);
  }
  for (int i = 0; i <= m; i++)
    if (a[i] <= n && b[m - i] <= n && a[i] < n - b[m - i] + 1) {
      printf("Yes\n%d %d", a[i] - k + 1, n - b[m - i] + 1);
      return 0;
    }
  puts("No");
  return 0;
}
