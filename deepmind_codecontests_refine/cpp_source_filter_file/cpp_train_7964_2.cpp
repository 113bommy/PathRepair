#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t input_size;
  std::cin >> input_size;
  std::vector<int> input(input_size), inverse(input_size);
  for (int i = 0; i < input_size; ++i) {
    int pos;
    std::cin >> pos;
    input[i] = --pos;
    inverse[pos] = i;
  }
  int answer = 0;
  for (auto it = inverse.begin(), next = inverse.begin() + 1;
       it != inverse.end() && next != inverse.end(); ++it, ++next) {
    answer += std::abs(*it - *next);
  }
  std::cout << answer;
  return 0;
}
