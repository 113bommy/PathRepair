#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MAXN = 200005;
template <typename T>
void read(T &x) {
  T flag = 1;
  char ch = getchar();
  for (; '0' > ch || ch > '9'; ch = getchar())
    if (ch == '-') flag = -1;
  for (x = 0; '0' <= ch && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  x *= flag;
}
int T;
int n;
char s[MAXN];
short a[MAXN];
int cnt[26];
int stk[MAXN];
void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  memset(cnt, 0, sizeof(cnt));
  int m = 0;
  for (int i = 1; i < n; i++)
    if (s[i] == s[i + 1]) cnt[s[i] - 'a']++;
  int mx = 0;
  int sum = cnt[0];
  for (int i = 1; i < 26; sum += cnt[i++])
    if (cnt[i] > cnt[mx]) mx = i;
  printf("%d\n", max((sum + 1) >> 1, cnt[mx]) + 1);
  int top = 0;
  for (int i = 1; i <= n; i++) {
    a[++m] = s[i] - 'a';
    if (m <= 1 || a[m] != a[m - 1]) continue;
    if (!top || a[stk[top]] == a[m]) {
      stk[++top] = m;
      continue;
    }
    mx = 0;
    for (int j = 1; j < 26; j++)
      if (cnt[j] > cnt[mx]) mx = max(mx, j);
    if (cnt[mx] * 2 < sum || a[m] == mx || a[stk[top]] == mx) {
      sum -= 2;
      cnt[a[m]]--;
      cnt[a[stk[top]]]--;
      printf("%d %d\n", stk[top], m - 1);
      a[stk[top]] = a[m];
      m = stk[top];
      top--;
    } else
      stk[++top] = m;
  }
  for (int i = m, lst = m; i; i--) {
    if (i == 1 || a[i - 1] == a[i]) printf("%d %d\n", i, lst), lst = i - 1;
  }
}
int main() {
  read(T);
  while (T--) solve();
  return 0;
}
