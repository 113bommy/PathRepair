#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool mini(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
bool maxi(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 4e5 + 5;
const int oo = 1e9;
int mn[N][20];
int a[N];
int n, root;
int getmin(int l, int r) {
  int d = log2(r - l + 1);
  int i = mn[l][d];
  int j = mn[r - (1 << d) + 1][d];
  return (a[i] < a[j]) ? i : j;
}
int calc(int l, int r) {
  if (l > r) return 0;
  int mid = getmin(l, r);
  return max(calc(l, mid - 1), calc(mid + 1, r)) + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) root = i;
    a[i + n] = a[i];
    mn[i][0] = i;
    mn[i + n][0] = i + n;
  }
  for (int j = 1; j < 20; j++)
    for (int i = 1; i + (1 << j) - 1 <= (n << 1); i++) {
      int x = mn[i][j - 1];
      int y = mn[i + (1 << (j - 1))][j - 1];
      mn[i][j] = (a[x] < a[y]) ? x : y;
    }
  int lo = 0;
  int hi = n + 1;
  while (hi - lo > 1) {
    int mid = (lo + hi) >> 1;
    int l = (root - mid + n) % n + 1;
    int r = l + n - 1;
    int pos = l + mid - 1;
    if (calc(l, pos - 1) < calc(pos + 1, r))
      lo = mid;
    else
      hi = mid;
  }
  int ans = oo;
  int res = 0;
  int l, r;
  if (lo > 0) {
    l = (root - lo + n) % n + 1;
    r = l + n - 1;
    if (mini(ans, calc(l, r))) res = l - 1;
  }
  if (hi <= n) {
    l = (root - hi + n) % n + 1;
    r = l + n - 1;
    if (mini(ans, calc(l, r))) res = l - 1;
  }
  cout << ans << " " << res << "\n";
  return 0;
}
