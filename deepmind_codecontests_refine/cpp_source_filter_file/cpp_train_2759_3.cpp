#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * f;
}
namespace qiqi {
const int N = 1e7 + 5;
int n, k, cnt, p[N], q[N], z[N];
char s[N], t[N], ans[N];
inline void Z(char *s, int n) {
  int l = 0, r = 0;
  z[1] = n;
  for (int i = (2); i <= (n); ++i) {
    if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
    while (s[1 + z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) r = i + z[l = i] - 1;
  }
}
inline void lyd(char *s, int n) {
  int i = 1;
  while (i <= n) {
    int j = i, k = i + 1;
    while (k <= n && s[j] <= s[k]) j = s[j] < s[k++] ? i : j + 1;
    while (i <= j) i += k - j;
    p[++cnt] = i - 1;
    q[cnt] = k - j;
  }
}
void main() {
  int x;
  scanf("%s", s + 1);
  int l = n = strlen(s + 1);
  k = read();
  reverse(s + 1, s + n + 1);
  reverse_copy(s + 1, s + n + 1, s + n + 2);
  s[n + 1] = '#';
  Z(s, n * 2 + 1);
  lyd(s, n);
  while (cnt && k > 2) {
    --k;
    --cnt;
    strncpy(ans + n - l + 1, s + p[cnt] + 1, l - p[cnt]);
    l = p[cnt];
    if (q[cnt + 1] == 1)
      while (q[cnt] == 1) {
        --cnt;
        strncpy(ans + n - l + 1, s + p[cnt] + 1, l - p[cnt]);
        l = p[cnt];
      }
  }
  if (cnt < 2 || k < 2) {
    x = n * 2 + 2 - l;
    strncpy(ans + n - l + 1, s[1 + z[x]] < s[x + z[x]] ? s + 1 : s + x, l);
    puts(ans + 1);
    return;
  }
  for (int i = (1); i <= (l); ++i) t[i + l] = t[i] = s[i];
  for (int i = 1; i <= l;) {
    int j = x = i, k = i + 1;
    while (k <= l * 2 && t[j] <= t[k]) j = t[j] < t[k++] ? i : j + 1;
    while (i <= j) i += k - j;
  }
  --x;
  strncpy(ans + n - l + 1, s + x + 1, l - x);
  strncpy(ans + n - x + 1, s + 1, x);
  strcpy(t + 1, ans + 1);
  x = 0;
  for (int i = (1); i <= (l - 1); ++i) {
    int p = z[n * 2 + 2 - i], q = z[i - x + 1];
    if (p <= i - x ? s[1 + p] < s[n * 2 + 2 - i + p]
                   : (q <= x && s[1 + i - x + q] < s[1 + q]))
      x = i;
  }
  strncpy(t + n - l + 1, s + n * 2 + 2 - l, l - x);
  strncpy(t + n - x + 1, s + 1, x);
  if (strcmp(t + 1, ans + 1) < 0) strcpy(ans + 1, t + 1);
  while (cnt && !strncmp(s + p[cnt] + 1, s + p[cnt - 1] + 1, l - p[cnt])) {
    if (strncmp(s + p[cnt - 1] + l - p[cnt] + 1, s + n * 2 + 2 - p[cnt],
                p[cnt] - p[cnt - 1]) > 0)
      break;
    --cnt;
  }
  x = p[cnt];
  strncpy(t + n - l + 1, s + x + 1, l - x);
  strncpy(t + n - x + 1, s + n * 2 + 2 - x, x);
  if (strcmp(t + 1, ans + 1) < 0) strcpy(ans + 1, t + 1);
  puts(ans + 1);
}
}  // namespace qiqi
int main() {
  qiqi::main();
  return 0;
}
