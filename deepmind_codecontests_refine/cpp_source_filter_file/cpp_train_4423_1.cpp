#include <bits/stdc++.h>
namespace fdd {
int n, m1, m2;
std::priority_queue<int> q[1010];
std::vector<int> v1, v2;
void solve() {
  std::cin >> n;
  for (int i = 3; i < n; i++) {
    scanf("%d%d", &m1, &m2);
    if (m1 > m2) std::swap(m1, m2);
    q[m1].push(m2);
  }
  for (int i = 2; i <= n; i++) {
    while (!q[i].empty()) {
      m1 = q[i].top();
      q[i].pop();
      v1.push_back(i);
      v1.push_back(m1);
    }
  }
  for (int i = 3; i < n; i++) {
    scanf("%d%d", &m1, &m2);
    if (m1 > m2) std::swap(m1, m2);
    q[m1].push(m2);
  }
  for (int i = 2; i <= n; i++) {
    while (!q[i].empty()) {
      m1 = q[i].top();
      q[i].pop();
      if (q[i].empty())
        m2 = m1 - 1;
      else
        m2 = q[i].top();
      v2.push_back(1);
      v2.push_back(m2);
    }
  }
  printf("%d\n", (v1.size() + v2.size()) >> 1);
  int l = v1.size();
  for (int i = 0; i < l; i += 2) printf("%d %d\n", v1[i], v1[i + 1]);
  l = v2.size();
  for (int i = l - 1; i >= 0; i -= 2) printf("%d %d\n", v2[i - 1], v2[i]);
}
}  // namespace fdd
int main() {
  fdd::solve();
  return 0;
}
