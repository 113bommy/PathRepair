#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int N = 4e5 + 10;
const int base = 2e5 + 5;
const int inf = 1e9;
int n;
int a[N];
int num[N];
int cnt[N], b[N];
bool cmp(int x, int y) { return cnt[x] > cnt[y]; }
int main() {
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    mx = max(mx, cnt[a[i]]);
  }
  int d = -1, res = 0;
  for (int i = 1; i <= n; i++)
    if (cnt[i] == mx) {
      res++;
      d = i;
    }
  if (res > 1) {
    printf("%d\n", n);
    return 0;
  }
  for (int i = 1; i <= n; i++) b[i] = i;
  sort(b + 1, b + n + 1, cmp);
  int ans = 0;
  for (int i = 2; i <= 200; i++)
    if (b[i] != d) {
      if (cnt[b[i]] == cnt[b[i - 1]]) ans = max(ans, cnt[b[i]]);
      memset(num, 0x3f3f3f, sizeof num);
      num[base] = 0;
      int sum = 0;
      for (int k = 1; k <= n; k++) {
        sum += (a[k] == b[i]);
        sum -= (a[k] == d);
        ans = max(ans, k - num[sum + base]);
        num[sum + base] = min(num[sum + base], k);
      }
    }
  printf("%d\n", ans);
  return 0;
}
