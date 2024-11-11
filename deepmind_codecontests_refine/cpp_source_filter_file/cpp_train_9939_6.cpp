#include <bits/stdc++.h>
const int N = 100005;
unsigned long long next(unsigned long long x) {
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  return x;
}
int n, a[N], lmid, rmid, mid, len, L, R;
long long ans = 0;
unsigned long long s[N];
int sum(int l, int r) { return s[r] - s[l - 1]; }
bool check(int l, int r) {
  int dis = std::min(n - r, l - 1);
  if (dis > len) return 0;
  if (r < rmid || l > lmid) {
    if (sum(l, r) != sum(n - r + 1, n - l + 1)) return 0;
    int dis = l > lmid ? l - rmid : lmid - r;
    if (dis > mid) return 0;
    return 1;
  } else {
    return l <= L && r >= R;
  }
}
int calc() {
  static int b[N], c[N];
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    std::memcpy(b, a, n + 1 << 2);
    std::sort(b + 1, b + mid);
    std::sort(b + mid, b + n + 1);
    if (std::set_difference(b + 1, b + mid, b + mid, b + n, c) - c)
      r = mid - 1;
    else
      ans = mid, l = mid + 1;
  }
  return ans;
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    s[i] = s[i - 1] + next(a[i]);
  }
  std::set<int> set;
  for (int i = 1; i <= n; ++i) {
    if (set.count(a[i]))
      set.erase(a[i]);
    else
      set.insert(a[i]);
  }
  if (set.size() > 1) return std::cout << "0\n", 0;
  L = calc();
  std::reverse(a + 1, a + n + 1);
  R = n + 1 - calc();
  std::reverse(a + 1, a + n + 1);
  a[0] = 0, a[n + 1] = n + 1;
  lmid = n >> 1, rmid = n + 1 >> 1;
  while (a[lmid - mid] == a[rmid + mid]) ++mid;
  while (a[len + 1] == a[n - len]) ++len;
  for (int r = 1, l = 0; r <= n; ans += l, ++r)
    while (l < r && check(l + 1, r)) ++l;
  std::cout << ans << '\n';
  return 0;
}
