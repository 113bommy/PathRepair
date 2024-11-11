#include <bits/stdc++.h>
using i64 = long long;
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> p(2 * n + 1), picked(2 * n + 1, false);
  std::priority_queue<std::pair<int, int>> q, prio_q;
  for (int i = 1; i <= 2 * n; i++) {
    std::cin >> p[i];
    q.emplace(p[i], i);
  }
  std::vector<int> a(2 * n + 1, -1);
  for (int i = 0; i < m; i++) {
    int c, d;
    std::cin >> c >> d;
    a[c] = d;
    a[d] = c;
    if (p[c] > p[d])
      prio_q.emplace(p[c], c);
    else
      prio_q.emplace(p[c], d);
  }
  int t, x = -1;
  std::cin >> t;
  t %= 2;
  for (int i = 0; i < 2 * n; i++) {
    if (i % 2 != t) {
      if (x > 0 && a[x] > 0 && !picked[a[x]]) {
        std::cout << a[x] << std::endl;
        std::cout.flush();
        picked[a[x]] = true;
      } else if (!prio_q.empty()) {
        auto next = prio_q.top();
        while (picked[next.second]) {
          if (prio_q.empty()) goto l;
          prio_q.pop();
          next = prio_q.top();
        }
        std::cout << next.second << std::endl;
        std::cout.flush();
        picked[next.second] = true;
        prio_q.pop();
      } else {
      l:
        auto next = q.top();
        while (picked[next.second]) {
          q.pop();
          next = q.top();
        }
        std::cout << next.second << std::endl;
        std::cout.flush();
        picked[next.second] = true;
        q.pop();
      }
    } else {
      std::cin >> x;
      if (x == -1) return 0;
      picked[x] = true;
    }
  }
  return 0;
}
