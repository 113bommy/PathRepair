#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const double ep = 1e-7;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1);
int m, k, n, s;
int a[maxn];
int b[maxn], cnt;
int c[maxn], cnt1, l = 1;
void solve() {
  scanf("%d%d", &(m), &(k));
  scanf("%d%d", &(n), &(s));
  for (register int i = (1); i <= (m); ++i) scanf("%d", &(a[i]));
  for (register int i = (1); i <= (s); ++i) {
    int x;
    scanf("%d", &(x));
    if (!b[x]) cnt++;
    b[x]++;
  }
  for (register int i = (1); i <= (m); ++i) {
    if (!b[a[i]]) continue;
    c[a[i]]++;
    if (c[a[i]] == b[a[i]]) cnt1++;
    while (!b[a[l]] || c[a[l]] > b[a[l]]) c[a[l]]--, l++;
    if (cnt1 == cnt) {
      int sum1 = (l - 1) / k;
      int sum2 = (m - i) / k;
      if (i - l + 1 >= k) {
        if (sum1 + sum2 + 1 < n) continue;
        int sum = i - l + 1 - k;
        if (sum1 >= n)
          sum1 = (l - 1) % k + (sum1 - n + 1) * k;
        else
          sum1 = (l - 1) % k;
        printf("%d\n", (sum + sum1));
        for (register int j = (1); j <= (l - 1); ++j) {
          if (!sum1) break;
          sum1--;
          printf("%d ", (j));
        }
        for (register int j = (l); j <= (i); ++j) {
          if (!sum) break;
          if (!b[a[j]]) {
            sum--;
            printf("%d ", (j));
            continue;
          }
          if (c[a[j]] > b[a[j]]) {
            sum--;
            c[a[j]]--;
            printf("%d ", (j));
          }
        }
        puts("");
        return;
      }
      int las1 = (l - 1) % k;
      int las2 = (m - i) % k;
      sum1 = (l - 1) / k;
      sum2 = (m - i) / k;
      if (sum1 + sum2 < n - 1) continue;
      if (sum1 + sum2 == n - 1 && las1 + las2 + (i - l + 1) < k) continue;
      if (las1 + i - l + 1 <= k)
        las1 = 0;
      else
        las1 -= k - (i - l + 1);
      if (sum1 >= n) las1 += (sum1 - n + 1) * k;
      printf("%d\n", (las1));
      for (register int j = (1); j <= (l - 1); ++j) {
        if (!las1) break;
        printf("%d ", (j));
        las1--;
      }
      puts("");
      return;
    }
  }
  puts("-1");
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) solve();
}
