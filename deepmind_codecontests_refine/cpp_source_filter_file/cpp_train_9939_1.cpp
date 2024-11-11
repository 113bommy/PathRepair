#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
const int mod = 1e9 + 7;
int n;
int a[N];
int f[N];
long long ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }
  for (int i = 0; i <= n; i++) ans += f[i] & 1;
  if (ans > 1) {
    cout << 0;
    return 0;
  }
  int l = 0, r = n - 1;
  while (l < r && a[l] == a[r]) l++, --r;
  if (l == r) {
    ans = (n * 1LL * (n + 1)) / 2;
    cout << ans;
    return 0;
  }
  memset(f, 0, sizeof f);
  int low = l, high = r, mid, i, j;
  while (low <= high) {
    mid = (low + high) >> 1;
    bool can = 1;
    for (i = l; i <= mid; i++) f[a[i]]++;
    for (i = r, j = l; j <= mid && i > mid; j++, i--) {
      if (!f[a[i]])
        can = 0;
      else
        f[a[i]]--;
    }
    for (j = mid + 1, i = r - (mid + 1 - l); j < i; j++, i--)
      can &= (a[i] == a[j]);
    for (i = l; i <= mid; i++) f[a[i]]--;
    for (i = r, j = l; j <= mid && j < i; j++, i--) {
      if (!f[a[i]])
        ;
      else
        f[a[i]]++;
    }
    if (can)
      high = mid - 1;
    else
      low = mid + 1;
  }
  int pre = low;
  low = l, high = r;
  while (low <= high) {
    mid = (low + high) >> 1;
    bool can = 1;
    for (i = mid; i <= r; i++) f[a[i]]++;
    for (i = l, j = r; j >= mid && i < mid; j--, i++) {
      if (!f[a[i]])
        can = 0;
      else
        f[a[i]]--;
    }
    for (j = mid - 1, i = l + (r - mid + 1); j > i; j--, i++)
      can &= (a[i] == a[j]);
    for (i = mid; i <= r; i++) f[a[i]]--;
    for (i = l, j = r; j >= mid && j > i; j--, i++) {
      if (!f[a[i]])
        ;
      else
        f[a[i]]++;
    }
    if (can)
      low = mid + 1;
    else
      high = mid - 1;
  }
  int suf = high;
  ans = 0;
  ans += (l + 1) * 1LL * (n - pre);
  ans += (suf - l) * 1LL * (n - r);
  cout << ans;
  return 0;
}
