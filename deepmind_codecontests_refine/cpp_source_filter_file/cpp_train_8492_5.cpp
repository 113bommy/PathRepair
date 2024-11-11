#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], ans[N], cnt[N];
inline int get(int k) {
  if (ans[k]) return ans[k];
  int p = 0, m = 0;
  for (int i = 0; i < n; i++) {
    m += !cnt[a[i]]++;
    if (m > k + 1) {
      ans[k]++;
      while (p < i) m -= !--cnt[a[p++]];
    }
  }
  while (p < n) cnt[a[p++]]--;
  return ++ans[k];
}
inline void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
}
inline void solve() {
  for (int i = 0; i < n;) {
    int L = i, R = n;
    while (R - L > 1) {
      int mid = L + R >> 1;
      (get(i) > get(mid) ? R : L) = mid;
    }
    fill(ans + i, ans + R, ans[i]), i = R;
  }
}
inline void write_output() {
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve(), write_output();
  return 0;
}
