#include <bits/stdc++.h>
int search(long long* a, int n, int x) {
  int l = -1, r = n;
  while (r - l != 1) {
    int m = (l + r) / 2;
    if (a[m] < x) {
      l = m;
    } else {
      r = m;
    }
  }
  return r;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  long long* a = new long long[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  long long* b = new long long[m];
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  long long* p = new long long[n];
  p[0] = a[0];
  for (int i = 1; i < n; ++i) {
    p[i] = p[i - 1] + a[i];
  }
  for (int i = 0; i < m; ++i) {
    int num = search(p, n, b[i]);
    if (num != 0) {
      std::cout << (num + 1) << " " << (b[i] - p[num - 1]) << "\n";
    } else {
      std::cout << 1 << " " << b[i] << "\n";
    }
  }
  return 0;
}
