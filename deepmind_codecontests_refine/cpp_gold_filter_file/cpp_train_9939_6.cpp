#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 3;
const int maxlog = 20;
const long long mod = 1e9 + 7;
const int maxh = 2 * 350;
int a[maxn], n, b[maxn], m;
int cnt[maxn];
bool ispal(int l, int r) {
  for (int i = l; i < r; i++)
    if (b[i] != b[m - i - 1]) return false;
  return true;
}
void prepare() {
  for (int i = 0; i < maxn; i++) cnt[i] = 0;
}
bool check(int pl) {
  for (int i = 0; i < pl; i++) cnt[b[i]]++;
  if (pl <= m / 2) {
    for (int i = m - pl; i < m; i++) {
      if (!cnt[b[i]]) {
        prepare();
        return false;
      } else
        cnt[b[i]]--;
    }
    if (ispal(pl, m - pl))
      return true;
    else
      return false;
  } else {
    for (int i = pl; i < m; i++) {
      if (!cnt[b[i]]) {
        prepare();
        return false;
      } else
        cnt[b[i]]--;
    }
    int c = 0;
    for (int i = 0; i < maxn; i++) {
      if (cnt[i] % 2 == 1) c++;
      cnt[i] = 0;
    }
    if (c < 2)
      return true;
    else
      return false;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout.precision(20);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = n - 1;
  while (l <= r) {
    if (a[l] == a[r])
      l++, r--;
    else
      break;
  }
  if (l > r) {
    long long ans = (long long)n * (long long)(n + 1) / 2;
    cout << ans;
    return 0;
  }
  for (int i = l; i <= r; i++) b[i - l] = a[i];
  m = r - l + 1;
  if (!check(m)) {
    cout << 0;
    return 0;
  }
  l = 1, r = m;
  int pre, suf;
  while (true) {
    if (l == r) {
      pre = l;
      break;
    }
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  reverse(b, b + m);
  l = 1, r = m;
  while (true) {
    if (l == r) {
      suf = l;
      break;
    }
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  int x = (n - m) / 2;
  long long ans = (long long)(x + 1) * (long long)(n - x - pre + m - suf + 1);
  cout << ans;
  return 0;
}
