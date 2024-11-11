#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[200100];
int d[200100], cnt[200100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  memset(cnt, 0, sizeof(cnt));
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[a[i]] = i;
    cnt[a[i]]++;
  }
  int last = 0, r = 1, ans = 0;
  int f = 1;
  for (int i = 1; i <= n; i++) {
    r = max(r, d[a[i]]);
    f = max(f, cnt[a[i]]);
    if (i == r) {
      ans += r + last - f;
      last = i;
      f = 0;
    }
  }
  cout << ans;
  return 0;
}
