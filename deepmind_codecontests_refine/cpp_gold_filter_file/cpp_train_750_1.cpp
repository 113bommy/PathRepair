#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, m;
char s[N];
int a[N], cnt[30];
int stk[N], top;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(cnt, 0, sizeof(cnt));
    int tot = 0, mx = 0;
    for (int i = 2; i <= n; i++) {
      if (s[i] == s[i - 1]) tot++, cnt[s[i] - 'a']++;
    }
    mx = *max_element(cnt, cnt + 26);
    printf("%d\n", max((tot + 1) / 2, mx) + 1);
    top = 0;
    m = 0;
    for (int i = 1; i <= n; i++) {
      a[++m] = s[i] - 'a';
      if (m <= 1 || a[m] != a[m - 1]) continue;
      if (!top || a[m] == a[stk[top]]) {
        stk[++top] = m;
        continue;
      }
      mx = max_element(cnt, cnt + 26) - cnt;
      if (cnt[mx] * 2 < tot || mx == a[m] || mx == a[stk[top]]) {
        tot -= 2;
        cnt[a[m]]--, cnt[a[stk[top]]]--;
        printf("%d %d\n", stk[top], m - 1);
        a[stk[top]] = a[m];
        m = stk[top--];
      } else
        stk[++top] = m;
    }
    for (int la = m, i = m; i >= 1; i--)
      if (i == 1 || a[i - 1] == a[i]) printf("%d %d\n", i, la), la = i - 1;
  }
  return 0;
}
