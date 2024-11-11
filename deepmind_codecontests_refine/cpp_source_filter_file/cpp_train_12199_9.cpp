#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
char s[N], t[N];
int mx[N], mn[N], ans;
int lens, lent;
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  lens = strlen(s + 1);
  lent = strlen(t + 1);
  int j = 1;
  for (int i = 1; i <= lens; ++i)
    if (s[i] == t[j]) mn[j++] = i;
  j = lent;
  for (int i = lens; i; --i)
    if (s[i] == t[j]) mx[j--] = i;
  ans = -N - 10000;
  for (int i = 1; i <= lent; ++i) ans = max(ans, mx[i] - mn[i]);
  ans = max(ans, max(lens - mn[lent], mx[1] - 1));
  printf("%d\n", ans);
  return 0;
}
