#include <bits/stdc++.h>
using namespace std;
int n, mn, mx;
int a[105];
int cnt[100005];
int ans[10005][105];
void solve(int x) {
  int sum = 0;
  int m = 0;
  int j = 1;
  for (int i = 1; i <= n; i++) {
    sum += a[i] - x;
  }
  m = max(sum / 5 + (sum % 5 != 0), mx - x);
  for (int i = 1; i <= m; i++) {
    cnt[i] = 0;
    for (int j = 1; j <= n; j++) {
      ans[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    int res = a[i] - x;
    while (res--) {
      cnt[j]++;
      ans[j++][i] = 1;
      if (j > m) j = 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (cnt[i] < 2) return;
  }
  cout << x << "\n";
  cout << m << "\n";
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
  exit(0);
}
int main() {
  cin >> n;
  mn = 101;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  if (mn == mx) {
    cout << mn << "\n";
    cout << 0;
    return 0;
  }
  for (int i = mn; i >= 1; i--) {
    solve(i);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = mx;
  }
  solve(0);
  return 0;
}
