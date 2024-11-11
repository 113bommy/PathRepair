#include <bits/stdc++.h>
using namespace std;
const int n0 = 1e5 + 123;
const array<int, 2> mod = {999999937, (int)1e9 + 9};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> _base(2, (int)1e9);
int n, a[n0], base, pw[2][n0];
int cnt[n0], num, odd, l, r, bal, mx, cmx;
struct Set {
  int cnt[n0];
  array<int, 2> val;
  void add2(int x) {
    if (x == odd) return;
    for (int i = 0; i < 2; i++) {
      val[i] += pw[i][x];
      if (val[i] >= mod[i]) val[i] -= mod[i];
    }
  }
  void del2(int x) {
    if (x == odd) return;
    for (int i = 0; i < 2; i++) {
      val[i] -= pw[i][x];
      if (val[i] < 0) val[i] += mod[i];
    }
  }
  void add(int x) {
    if (cnt[x] & 1) del2(x);
    cnt[x]++;
    if (cnt[x] & 1) add2(x);
  }
  void del(int x) {
    if (cnt[x] & 1) del2(x);
    cnt[x]--;
    if (cnt[x] & 1) add2(x);
  }
  bool operator==(const Set& s) const {
    return val[0] == s.val[0] && val[1] == s.val[1];
  }
};
Set s1, s2;
void add2(int i) {
  if (s1.cnt[a[i]] < s2.cnt[a[i]]) bal--;
  s2.add(a[i]);
  if (s1.cnt[a[i]] < s2.cnt[a[i]]) bal++;
}
void del2(int i) {
  if (s1.cnt[a[i]] < s2.cnt[a[i]]) bal--;
  s2.del(a[i]);
  if (s1.cnt[a[i]] < s2.cnt[a[i]]) bal++;
}
void add1(int i) {
  if (i != n - i + 1) {
    if (n - i + 1 < l || n - i + 1 > r)
      add2(n - i + 1);
    else
      del2(i);
  }
  if (s1.cnt[a[i]] < s2.cnt[a[i]]) bal--;
  s1.add(a[i]);
  if (s1.cnt[a[i]] < s2.cnt[a[i]]) bal++;
}
void del1(int i) {
  if (i != n - i + 1) {
    if (n - i + 1 < l || n - i + 1 > r)
      del2(n - i + 1);
    else
      add2(i);
  }
  if (s1.cnt[a[i]] < s2.cnt[a[i]]) bal--;
  s1.del(a[i]);
  if (s1.cnt[a[i]] < s2.cnt[a[i]]) bal++;
}
bool ok() {
  int o = 1;
  if (odd) {
    if (s1.cnt[odd] < s2.cnt[odd])
      o = 0;
    else {
      if ((s1.cnt[odd] & 1) != (s2.cnt[odd] & 1))
        o = (l <= (n + 1) / 2 && (n + 1) / 2 <= r) || (a[(n + 1) / 2] == odd);
    }
  }
  int c = 1, mid = (n + 1) / 2;
  if (n & 1) {
    if (l > mid) c = (cmx >= l - mid - 1);
    if (r < mid) c = (cmx >= mid - r - 1);
  } else {
    if (l >= mid + 1) c = (cmx >= l - (mid + 1));
    if (r >= mid) c = (cmx >= mid - r);
  }
  return (bal == 0 && s1 == s2 && mx >= min(l, n - r + 1) && o && c);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  base = _base(rng);
  for (int i = 0; i < 2; i++) {
    pw[i][0] = 1;
    for (int j = 1; j < n0; j++)
      pw[i][j] = (long long)pw[i][j - 1] * base % mod[i];
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i], cnt[a[i]]++;
  }
  for (int i = 1; i <= n / 2; i++) {
    if (a[i] != a[n - i + 1]) break;
    mx = i;
  }
  mx++;
  int mid = n / 2;
  while (mid >= 1) {
    if (a[mid] != a[n - mid + 1]) break;
    mid--, cmx++;
  }
  for (int i = 1; i <= n; i++)
    if (cnt[i] & 1) num++, odd = i;
  if (num > 1) return cout << 0, 0;
  if (num && !(n & 1)) return cout << 0, 0;
  long long ans = 0;
  l = 1, r = 0;
  while (l <= n) {
    while (r + 1 <= l) {
      add1(r + 1), r++;
    }
    while (r + 1 <= n) {
      if (ok()) break;
      add1(r + 1), r++;
    }
    if (ok()) ans += n - r + 1;
    del1(l), l++;
  }
  cout << ans;
}
