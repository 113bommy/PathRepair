#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, cnt[N], prv[N];
inline bool check(int x, int y) {
  long long ted = 0;
  int mx1 = 0, mx2 = 0, mx3 = 0;
  for (int i = y; i < N + y; i += y) {
    int z = prv[min(i, N - 1)];
    if (z >= x && make_pair(z % y, z) > make_pair(mx1 % y, mx1)) {
      mx2 = mx1, mx1 = z;
      if (cnt[z] - cnt[z - 1] > 1) mx2 = z;
    }
    for (auto t : {prv[z], z})
      if (t >= x && t % y >= mx2 % y &&
          make_pair(t % y, t) < make_pair(mx1 % y, mx1))
        mx2 = t;
    if (z >= x + x && z % y >= mx3 % y) mx3 = z;
    ted += i / y * (cnt[min(i + y - 1, N - 1)] - cnt[min(i - 1, N - 1)]);
  }
  if ((cnt[y - 1] - cnt[x - 1] > 1 || prv[y] / x > 1) && ted >= x) return true;
  if (cnt[y - 1] > cnt[x - 1] && mx1 && ted - mx1 / y + (mx1 - x) / y >= x)
    return true;
  if (mx1 && mx2 &&
      ted - mx1 / y - mx2 / y + (mx1 - x) / y + (mx2 - x) / y >= x)
    return true;
  return mx3 && ted - mx3 / y + (mx3 - x - x) / y >= x;
}
inline void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
}
inline void solve() {
  long long ans = 0;
  for (int i = 1; i < N - 1; i++) prv[i + 1] = cnt[i] ? i : prv[i];
  partial_sum(cnt, cnt + N, cnt);
  for (int y = 2, R = N; y < N; y++) {
    for (int L = 0; R - L > 1;) (check(L + R >> 1, y) ? L : R) = L + R >> 1;
    if (R > 2) ans = max(ans, (R - 1LL) * y);
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve();
  return 0;
}
