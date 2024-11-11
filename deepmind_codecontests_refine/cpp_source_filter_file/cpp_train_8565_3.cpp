#include <bits/stdc++.h>
using namespace std;
struct dang {
  long long x, y;
};
dang a[200200];
bool cmp(dang a, dang b) { return a.x < b.x; }
long long s[200200], ans;
dang check(int m) {
  dang ss;
  ss.x = a[m].x;
  ss.y = s[m + 1];
  return ss;
}
void work(int m) {
  long long ss;
  ss = max(a[m].x, s[m + 1]);
  ans = min(ss, ans);
}
int main() {
  int t, l, r, m, n, i, j, k;
  dang ss;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a[i].x;
    }
    for (i = 1; i <= n; i++) {
      cin >> a[i].y;
    }
    sort(a + 1, a + n + 1, cmp);
    s[n] = a[n].y;
    for (i = i - 1; i >= 1; i--) s[i] = s[i + 1] + a[i].y;
    l = 0;
    r = n;
    while (l + 1 < r) {
      m = (l + r) / 2;
      ss = check(m);
      if (ss.x > ss.y)
        r = m;
      else
        l = m;
    }
    ans = 999999999999999;
    s[n + 1] = 0;
    a[0].x = 0;
    if (l - 3 >= 0) work(l - 3);
    if (l - 2 >= 0) work(l - 2);
    if (l - 1 >= 0) work(l - 1);
    if (l >= 0) work(l);
    if (l + 1 <= n) work(l + 1);
    if (l + 2 <= n) work(l + 2);
    if (l + 3 <= n) work(l + 3);
    cout << ans << endl;
  }
  return 0;
}
