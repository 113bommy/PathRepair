#include <bits/stdc++.h>
std::string output(int what, int base) {
  int i;
  std::string lemur;
  std::vector<int> answer;
  while (what > 0) {
    answer.push_back(what % base);
    what /= base;
  }
  for (i = answer.size() - 1; i >= 0; --i) {
    lemur += (char)('0' + answer[i]);
  }
  return lemur;
}
int main(void) {
  int i, j, k;
  std::cin >> k;
  for (i = 1; i <= k; ++i) {
    for (j = 1; j <= k; ++j) {
      std::cout << output(i * j, k) << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
