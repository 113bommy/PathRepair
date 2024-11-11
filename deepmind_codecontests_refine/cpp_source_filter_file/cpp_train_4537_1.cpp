#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 8;
long long Tree[maxn + 8];
inline long long lowbit(long long x) { return (x & -x); }
inline void add(long long x, long long val) {
  for (long long i = x; i <= maxn; i += lowbit(i)) Tree[i] += val;
}
inline long long get(long long x) {
  long long sum = 0;
  for (long long i = x; i; i -= lowbit(i)) sum += Tree[i];
  return (sum);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, ans = 2, x, y;
  cin >> n >> k;
  cout << ans;
  if (k > n / 2) k = n - k;
  add(1, 1);
  add((1 + k), 1);
  x = 1 + k;
  for (int i = 2; i <= n; i++) {
    y = x + k;
    while (y > n) y -= n;
    if (y > x) {
      ans += get(y - 1) - get(x) + 1;
    } else {
      ans += get(y - 1) + get(n) - get(x) + 1;
    }
    add(x, 1);
    add(y, 1);
    x = y;
    cout << " " << ans;
  }
  return 0;
}
