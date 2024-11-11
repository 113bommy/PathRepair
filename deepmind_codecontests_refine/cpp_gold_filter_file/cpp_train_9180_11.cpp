#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
char s[maxn];
int sum[maxn], pre[maxn];
int judge(int x, int mark, int n) {
  int ans = mark + x;
  if (ans > n) ans -= n;
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  int mins = 0x3f3f3f3f, mark = 0;
  sum[1] = pre[1] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(')
      sum[i + 1] = sum[i] + 1;
    else
      sum[i + 1] = sum[i] - 1;
    if (sum[i] < mins) {
      mins = sum[i];
      mark = i;
    }
  }
  if (sum[n + 1] != 0) {
    printf("0\n1 1\n");
    return 0;
  }
  for (int i = mark; i <= n; i++) pre[i - mark] = sum[i] - mins;
  for (int i = 1; i < mark; i++) pre[(i - mark + n) % n] = sum[i] - mins;
  int ans1 = 0, cnt1 = 0, res1 = 0, l1 = 0x3f3f3f3f, r1 = 0, x1 = 0, y1 = 0;
  for (int i = 0; i < n; i++)
    if (pre[i] == 0) ans1++;
  for (int i = 0; i < n; i++) {
    if (pre[i] >= 2) {
      if (pre[i] == 2) cnt1++, l1 = min(l1, i), r1 = max(r1, i);
    } else {
      if (res1 < cnt1) {
        res1 = cnt1;
        x1 = l1 - 1, y1 = r1;
      }
      l1 = 0x3f3f3f3f, r1 = 0;
      cnt1 = 0;
    }
  }
  ans1 += res1;
  int ans2 = 0, cnt2 = 0, last = 0, x2 = 0, y2 = 0;
  for (int i = 0; i < n; i++) {
    if (pre[i] != 0) {
      if (pre[i] == 1) cnt2++;
    } else {
      if (ans2 < cnt2) {
        ans2 = cnt2;
        x2 = last, y2 = i - 1;
      }
      cnt2 = 0;
      last = i;
    }
  }
  if (ans2 < cnt2) {
    ans2 = cnt2;
    x2 = last, y2 = n - 1;
  }
  x1 = judge(x1, mark, n);
  x2 = judge(x2, mark, n);
  y1 = judge(y1, mark, n);
  y2 = judge(y2, mark, n);
  if (ans1 > ans2)
    printf("%d\n%d %d\n", ans1, x1, y1);
  else
    printf("%d\n%d %d\n", ans2, x2, y2);
  return 0;
}
