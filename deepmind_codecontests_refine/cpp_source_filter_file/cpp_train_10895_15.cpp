#include <bits/stdc++.h>
std::vector<int> V, Q[1 << 17];
int n, m, a[1 << 17], b[1 << 17], c[1 << 17], A = 1, x;
int C(int x) {
  for (auto o : V) x = std::min(x, x ^ o);
  return x;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &x, &b[i]), Q[x].push_back(i);
  for (int i = 1; i <= n; ++i) {
    C(a[i]) ? V.push_back(C(a[i])), 0 : (A *= 2) %= 1000000007;
    for (auto o : Q[i]) c[o] = C(b[o]) ? 0 : A;
  }
  for (int i = 1; i <= n; ++i) printf("%d\n", c[i]);
}
