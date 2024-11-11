#include <bits/stdc++.h>
using namespace std;
int cnt[201];
struct pot {
  int f, s;
  pot() {
    f = 0;
    s = 0;
  }
  bool operator<(pot other) const {
    if (fabs(f - other.f) > pow(10, -9)) return f < other.f;
  }
};
int main() {
  int n, k;
  cin >> n;
  struct pot a[n + 3];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].f);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].s);
    cnt[a[i].s]++;
  }
  sort(a + 1, a + n + 1);
  int suf[n + 3];
  suf[n] = 0;
  for (int i = n - 1; i > 0; i--) {
    suf[i] = a[i + 1].s + suf[i + 1];
  }
  int j = n, mx = 1000000000, ans = 0, cl, mn, i = n;
  while (i > 0) {
    ans = 0;
    j = i;
    int ct = 0;
    while (j > 0 && a[i].f == a[j].f) {
      ct = 1;
      cnt[a[j].s]--;
      j--;
    }
    ans += suf[i];
    if (i - j > j) {
      mx = min(ans, mx);
    } else {
      cl = 2 * j - i + 1;
      for (int k = 1; k <= 200; k++) {
        mn = min(cl, cnt[k]);
        ans += mn * k;
        cl -= mn;
      }
    }
    mx = min(mx, ans);
    i = j;
    if (ct == 0) i--;
  }
  cout << mx;
}
