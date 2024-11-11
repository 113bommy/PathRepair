#include <bits/stdc++.h>
int main() {
  std::map<std::string, std::string> WordsMap;
  int n, m;
  std::cin >> n >> m;
  std::string first, second;
  for (int i = 0; i < m; i++) {
    std::cin >> first >> second;
    if (first.size() <= second.size()) {
      WordsMap[first] = first;
    } else {
      WordsMap[first] = second;
    }
  }
  for (int i = 0; i < n; i++) {
    std::cin >> first;
    std::cout << WordsMap[first];
  }
}
