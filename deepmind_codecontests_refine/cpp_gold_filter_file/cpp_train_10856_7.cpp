#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int m = n * 2;
  std::vector<char> c(m);
  std::vector<int> a(m, 0);
  for (int i = 0; i < m; i++) {
    std::cin >> c[i];
    if (c[i] == '-') {
      std::cin >> a[i];
    }
  }
  std::vector<int> sta(n + 2, 0), s(n + 2, 0);
  int top = 0;
  auto failed = [&]() {
    std::cout << "NO" << '\n';
    exit(0);
  };
  std::vector<int> f(n + 1, 0);
  auto doit = [&](int k) {
    if (s[k] || !top || k < f[sta[top]]) {
      failed();
    }
    s[k] = 1;
    f[sta[top]] = k;
    top--;
    f[sta[top]] = std::max(f[sta[top]], k);
  };
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (c[i] == '+') {
      ++cnt;
      sta[++top] = cnt;
    } else {
      doit(a[i]);
    }
  }
  std::vector<int> g(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    g[f[i]]++;
  }
  for (int i = n; i >= 1; i--) {
    g[i] += g[i + 1];
    if (g[i] > n - i + 1) {
      failed();
    }
  }
  std::cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << f[i] << ' ';
  }
  return 0;
}
