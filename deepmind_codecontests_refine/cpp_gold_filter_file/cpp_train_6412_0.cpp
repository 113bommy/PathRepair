#include <bits/stdc++.h>
int a[500000], b[500000], n;
std::priority_queue<std::pair<long long, int> > q;
inline std::pair<long long, int> solve(int c) {
  std::pair<long long, int> ans = {0, 0};
  while (!q.empty()) q.pop();
  for (int i = 0; i < n; i++) {
    q.push({-a[i], 0});
    int first = b[i] - c;
    std::pair<long long, int> u = q.top();
    if (first - u.first < 0) {
      ans.first += first - u.first;
      ans.second += 1 - u.second;
      q.pop();
      q.push({first, 1});
    }
  }
  return ans;
}
int main() {
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int rez = 0;
  long long ans = 0;
  for (int pas = 1 << 30; pas; pas >>= 1) {
    std::pair<long long, int> u = solve(rez + pas);
    if (u.second <= k) {
      rez += pas;
      ans = u.first + 1LL * rez * k;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
