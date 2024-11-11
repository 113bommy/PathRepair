#include <bits/stdc++.h>
int mod(long long a, long long n) { return (a >= n) ? (a % n) : a; }
int mul(long long a, long long b, long long n) { return mod(a * b, n); }
int main(void) {
  int i, n;
  std::vector<int> a, b, c;
  std::cin >> n;
  if (n % 2 == 0) {
    std::cout << "-1\n";
    return 0;
  }
  for (i = 0; i < n; ++i) {
    a.push_back(i);
    b.push_back(mul(n - 2, i, n));
    c.push_back(mul(n - 1, i, n));
  }
  for (i = 0; i < n; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
  for (i = 0; i < n; ++i) {
    std::cout << b[i] << " ";
  }
  std::cout << "\n";
  for (i = 0; i < n; ++i) {
    std::cout << c[i] << " ";
  }
  std::cout << "\n";
  return 0;
}
