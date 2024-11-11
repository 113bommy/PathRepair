#include <bits/stdc++.h>
int main() {
  int cases;
  std::cin >> cases;
  int n;
  for (int z = 0; z < cases; z++) {
    long long m;
    std::cin >> n >> m;
    long long sum = 0;
    long long input;
    for (int x = 0; x < n; x++) {
      std::cin >> input;
      sum += input;
    }
    if (sum == m)
      std::cout << "YES";
    else
      std::cout << "NO";
  }
  return 0;
}
