#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, a[maxn], cnt[maxn], mx = 0, last[maxn * 2], ans = 0;
void solve1(int x) {
  for (int i = 1; i <= n; i++) last[n - i] = last[n + i] = -1;
  last[n] = 0;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == x)
      cur++;
    else if (a[i] == mx)
      cur--;
    if (last[n + cur] == -1)
      last[n + cur] = i;
    else
      ans = max(ans, i - last[n + cur]);
  }
}
void solve2(int limit) {
  memset(cnt, 0, sizeof cnt);
  int equal = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    cnt[a[i]]++;
    if (cnt[a[i]] == limit) equal++;
    if (cnt[a[i]] > limit) {
      while (j <= i && cnt[a[i]] > limit) {
        cnt[a[j]]--;
        if (cnt[a[j]] == limit - 1) equal--;
        j++;
      }
    }
    if (equal >= 2) ans = max(ans, i - j + 1);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    mx = cnt[mx] < cnt[a[i]] ? a[i] : mx;
  }
  int limt = sqrt(n);
  for (int i = 1; i <= n; i++)
    if (cnt[i] >= limt && i != mx) solve1(i);
  for (int i = 1; i < limt; i++) solve2(i);
  cout << ans << endl;
}
