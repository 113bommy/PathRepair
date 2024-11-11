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
const int N = 1e7 + 6;
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
inline void solve(char *res, int len) {
  int k = n * 2 + 2 - len;
  strncpy(res, s[1 + z[k]] < s[k + z[k]] ? s + 1 : s + k, len);
}
void main() {
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
  if (cnt == 1 || k < 2) {
    solve(ans + n - l + 1, l);
    puts(ans + 1);
    return;
  }
  strcpy(t + 1, ans + 1);
  strncpy(ans + n - l + 1, s + p[cnt - 1] + 1, l - p[cnt - 1]);
  strncpy(t + n - l + 1, s + p[cnt - 2] + 1, l - p[cnt - 2]);
  solve(ans + n - p[cnt - 1] + 1, p[cnt - 1]);
  solve(t + n - p[cnt - 2] + 1, p[cnt - 2]);
  if (strcmp(t + 1, ans + 1) < 0) strcpy(ans + 1, t + 1);
  int k = 1, a, b;
  for (int i = (2); i <= (l - 1); ++i) {
    b = z[a = n * 2 + 1 - l + k];
    if (b < i - k) {
      if (s[a + b] < s[1 + b]) k = i;
    } else {
      b = z[i - k + 1];
      if (s[1 + b] < s[i - k + b]) k = i;
    }
  }
  --k;
  strncpy(t + n - l + 1, s + n * 2 + 2 - l, k);
  strncpy(t + n - l + k + 1, s + 1, l - k);
  if (strcmp(t + 1, ans + 1) < 0) strcpy(ans + 1, t + 1);
  puts(ans + 1);
}
}  // namespace qiqi
int main() {
  qiqi::main();
  return 0;
}
