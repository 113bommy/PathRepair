#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int n, tot, S, cnt, now, ans;
int bj[1000005], jl[1000005];
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (i == 0 || s[i] != s[i - 1])
      bj[++tot] = 1;
    else
      bj[tot] = 0;
  }
  if (s[n - 1] == s[0]) bj[1] = 0, tot--;
  S = 1;
  for (int i = 1; i <= n; ++i)
    if (bj[i]) {
      S = i;
      break;
    }
  for (int i = S; i <= tot; ++i) jl[++cnt] = bj[i];
  for (int i = 1; i < S; ++i) jl[++cnt] = bj[i];
  for (int i = 1; i <= cnt; ++i) {
    if (jl[i])
      now++;
    else {
      ans += now / 2 + 1;
      now = 0;
    }
  }
  ans += now / 2;
  printf("%d", ans);
  return 0;
}
