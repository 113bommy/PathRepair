#include <bits/stdc++.h>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  auto x = find(a.begin(), a.end(), -1);
  fill(a.begin(), x, 0);
  a.erase(x);
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  int p = 0;
  i64 ans = 0;
  reverse(a.begin(), a.end());
  for (int len = n / 2; len > 0; len /= 2) {
    q.push(a[p]);
    ans += a[p];
    q.pop();
    for (int i = p + 1; i < p + len; i++) {
      q.push(a[i]);
    }
    p += len;
  }
  std::cout << ans << "\n";
  return 0;
}
