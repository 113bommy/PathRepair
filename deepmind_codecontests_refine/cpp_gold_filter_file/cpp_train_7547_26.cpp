#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 7;
int n, q;
int a[MAXN];
int l[MAXN], r[MAXN];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < n; i++) a[i] = abs(a[i + 1] - a[i]);
  for (int i = 1; i < n; i++) l[i] = r[i] = i;
  for (int i = 2; i < n; i++) {
    int now = i;
    while (now > 1 && a[i] >= a[now - 1]) now = l[now - 1];
    l[i] = now;
  }
  for (int i = n - 1 - 1; i >= 1; i--) {
    int now = i;
    while (now < n - 1 && a[i] > a[now + 1]) now = r[now + 1];
    r[i] = now;
  }
  while (q--) {
    int beg, end;
    cin >> beg >> end;
    long long ans = 0;
    for (int i = beg; i < end; i++) {
      int x = max(beg, l[i]);
      int y = min(end - 1, r[i]);
      ans += 1LL * (i - x + 1) * (y - i + 1) * a[i];
    }
    cout << ans << endl;
  }
  return 0;
}
