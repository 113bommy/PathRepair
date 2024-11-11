#include <bits/stdc++.h>
int main() {
  int32_t n;
  std::cin >> n;
  std::string* target = new std::string[n];
  for (int32_t i = 0; i < n; i++) {
    std::cin >> target[i];
  }
  bool *inverted_row = new bool[n], *inverted_col = new bool[n];
  bool* diagonal = new bool[n];
  for (int32_t i = 0; i < n; i++) {
    inverted_row[i] = false;
    inverted_col[i] = false;
    diagonal[i] = false;
  }
  int32_t answer = 0;
  for (int32_t i = n - 1; i > 0; i--) {
    for (int32_t j = 0; j < i; j++) {
      bool cur_state = inverted_row[i] ^ inverted_col[j];
      if ((cur_state && target[i][j]) == '0' ||
          (!cur_state && target[i][j] == '1')) {
        inverted_row[i] = !inverted_row[i];
        inverted_col[j] = !inverted_col[j];
        diagonal[i] = !diagonal[i];
        diagonal[j] = !diagonal[j];
        answer++;
      }
    }
  }
  for (int32_t i = 0; i < n; i++) {
    inverted_row[i] = false;
    inverted_col[i] = false;
  }
  for (int32_t i = 0; i < n - 1; i++) {
    for (int32_t j = n - 1; j > i; j--) {
      bool cur_state = inverted_row[i] ^ inverted_col[j];
      if ((cur_state && target[i][j]) == '0' ||
          (!cur_state && target[i][j] == '1')) {
        inverted_row[i] = !inverted_row[i];
        inverted_col[j] = !inverted_col[j];
        diagonal[i] = !diagonal[i];
        diagonal[j] = !diagonal[j];
        answer++;
      }
    }
  }
  for (int32_t i = 0; i < n; i++)
    if ((diagonal[i] && target[i][i] == '0') ||
        (!diagonal[i] && target[i][i] == '1'))
      answer++;
  std::cout << answer;
  return 0;
}
