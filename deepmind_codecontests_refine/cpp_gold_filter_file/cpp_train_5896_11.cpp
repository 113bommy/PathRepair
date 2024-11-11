#include <bits/stdc++.h>
int gi() {
  int x;
  std::cin >> x;
  return x;
}
int main() {
  int n = gi();
  std::set<int> s;
  for (int i = 0; i < n; i++) s.insert(gi());
  std::cout << n + 1 - s.size();
  return 0;
}
