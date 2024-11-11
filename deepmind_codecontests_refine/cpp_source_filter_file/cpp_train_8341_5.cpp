#include <bits/stdc++.h>
using LL = long long;
using ULL = int long long;
void init() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
}
int main() {
  init();
  int n;
  std::cin >> n;
  std::unordered_map<int, int> xors[2];
  xors[1][0] = 1;
  int total = 0;
  int currXorSum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    currXorSum ^= x;
    total += xors[i % 2][currXorSum];
    ++xors[i % 2][currXorSum];
  }
  std::cout << total << '\n';
  return 0;
}
