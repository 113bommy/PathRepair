#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::priority_queue<int> q;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    q.push(a[i]);
    if (q.top() > a[i]) {
      ans += q.top() - a[i];
      q.pop();
      q.push(a[i]);
    }
  }
  std::cout << ans << "\n";
  return 0;
}
