#include <bits/stdc++.h>
using namespace std;
typedef struct Res {
  long long x;
  long long y;
} Res;
Res s[200005];
long long Pow(int x, int y) {
  int i;
  long long ans = 1;
  for (i = 1; i <= y; i++) ans = ans * x;
  return ans;
}
bool comp(long long a, long long b) { return a > b; }
long long val[200005];
int main(void) {
  long long now, temp, bet, ans = 0;
  int n, a, b, i, last;
  scanf("%d%d%d", &n, &a, &b);
  b = min(b, n);
  for (i = 1; i <= n; i++) {
    scanf("%I64d%I64d", &s[i].x, &s[i].y);
    ans += s[i].y;
    val[i] = s[i].x - s[i].y;
  }
  sort(val + 1, val + n + 1, comp);
  if (b == 0)
    printf("%I64d\n", ans);
  else {
    for (i = 1; i <= n; i++) {
      if (i <= b) {
        if (val[i] <= 0) {
          last = i - 1;
          break;
        } else
          ans += val[i];
      } else {
        last = i - 1;
        break;
      }
    }
    if (i == n + 1) last = n;
    bet = ans;
    for (i = 1; i <= n; i++) {
      temp = s[i].x - s[i].y;
      now = s[i].x * Pow(2, a) - s[i].y;
      if (temp >= val[last])
        bet = max(bet, ans - temp + now);
      else if (last == b)
        bet = max(bet, ans - val[last] + now);
      else
        bet = max(bet, ans + now);
    }
  }
  printf("%I64d\n", bet);
  return 0;
}
