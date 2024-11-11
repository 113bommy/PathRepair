#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::sort(a.rbegin(), a.rend());
  int teams = 0;
  int i = 0;
  while (i < n) {
    int size = 1;
    while (i < n && x > a[i] * size) {
      i++;
      size++;
    }
    if (x <= a[i] * size) teams++;
    i++;
  }
  std::cout << teams << "\n";
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
