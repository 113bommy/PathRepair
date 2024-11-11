#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, L, R, q1, q2;
  cin >> n >> L >> R >> q1 >> q2;
  vector<int> w(n);
  for (auto& x : w) cin >> x;
  vector<long long> l(n + 1), r(n + 1);
  for (int i = 1; i < n + 1; i++) {
    l[i] = l[i - 1] + w[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    r[i] = r[i + 1] + w[i];
  }
  long long ans = 1e18, cnt = 0;
  for (int i = 0; i < n + 1; i++) {
    cnt = L * l[i] + R * r[i];
    if (n - i >= i) {
      cnt += max(0, (n - 1 - 2 * i)) * q2;
    } else {
      cnt += max(0, (2 * i - n - 1)) * q1;
    }
    ans = min(cnt, ans);
  }
  cout << ans << "\n";
  return 0;
}
