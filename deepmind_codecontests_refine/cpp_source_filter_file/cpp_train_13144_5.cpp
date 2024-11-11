#include <bits/stdc++.h>
using uint = unsigned int;
int main() {
  int t;
  scanf("%i", &t);
  while (t--) {
    int n;
    scanf("%i", &n);
    std::string a(n, (char)0);
    std::cin >> a;
    int sumset[100000]{};
    long long out{};
    int sum{};
    for (int i{}; i < n; ++i) {
      sum += a[i] - 49;
      ++sumset[sum + 50000];
    }
    for (int i{0}; i < 100000; ++i)
      out += (((long long)sumset[i] * (sumset[i] - 1)) >> 1);
    out += sumset[50000];
    std::cout << out << '\n';
  }
  return 0;
}
