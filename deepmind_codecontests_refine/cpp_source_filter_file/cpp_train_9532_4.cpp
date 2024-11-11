#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int m, n, a[maxn];
long long s[maxn];
bool vis[maxn];
bool check(int x) {
  if (!vis[x]) return 1;
  int m1 = m - x, i = n;
  while (m1) {
    if (a[i] > m1) {
      int l = 1, r = i, mid, ret;
      while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] > m1) {
          ret = mid;
          r = mid - 1;
        } else
          l = mid + 1;
      }
      i = ret - 1;
    }
    if (!i) return 0;
    int l = 1, r = i, mid, ret = -1;
    while (l <= r) {
      mid = (l + r) / 2;
      if (s[i] - s[mid - 1] <= m1) {
        ret = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    m1 -= (s[i] - s[ret - 1]);
    i = ret - 1;
  }
  return 1;
}
int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int m1 = m, o = m;
  for (int i = n; i >= 1 && m1; i--)
    if (m1 >= a[i]) {
      for (int j = o; j >= a[i]; j--) vis[j] = 1;
      o = a[i] - 1;
      m1 -= a[i];
    }
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  int ans;
  for (ans = 1; ans <= m && check(ans); ans++)
    ;
  if (ans <= m)
    cout << ans;
  else
    cout << "Greed is good";
  return 0;
}
