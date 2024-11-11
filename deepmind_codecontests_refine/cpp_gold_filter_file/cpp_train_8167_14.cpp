#include <bits/stdc++.h>
using AT = std::vector<int>;
using dict = std::unordered_map<int, int>;
using ll = long long;
int read() {
  int t{};
  std::cin >> t;
  return t;
}
void readArr(AT& arr) {
  for (int i = 0; i < arr.size(); i++) std::cin >> arr[i];
}
void print(ll ans) { std::cout << ans << '\n'; }
void print(int ans) { std::cout << ans << '\n'; }
bool isPrime(int m) {
  if (m < 4) return true;
  if (m % 2 == 0) return false;
  for (int i{3}; i < m / 2 + 1; i += 2) {
    if (m % i == 0) return false;
  }
  return true;
}
int main() {
  using namespace std;
  int n{read()}, second{read()};
  AT back(n);
  readArr(back);
  int sum{1};
  while (sum < second) {
    sum += back[sum - 1];
  }
  cout << ((sum == second) ? "YES" : "NO") << '\n';
}
