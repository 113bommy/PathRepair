#include <bits/stdc++.h>
using namespace std;
const int MaxN = 3e5;
char s[MaxN + 5];
long long Solve(int l, int r, int cas) {
  if (cas == 4) return 0LL;
  long long ans = 0;
  for (int i = l + 2 * cas; i <= r; i++) {
    if (s[i] == s[i - cas] && s[i] == s[i - 2 * cas]) {
      ans = (long long)(r - i + 1) * (i - 2 * cas - l + 1);
      ans += Solve(l, i - 1, cas + 1);
      ans += Solve(i - 2 * cas + 1, r, cas);
      return ans;
    }
  }
  return Solve(l, r, cas + 1);
}
int main() {
  int n;
  long long ans = 0;
  scanf(" %s", s + 1);
  n = strlen(s + 1);
  ans = Solve(1, n, 1);
  printf("%I64d\n", ans);
  return 0;
}
