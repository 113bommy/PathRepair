#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::tuple;
using std::vector;
int64_t ReadData();
vector<size_t> Solution(int64_t data);
void WriteAnswer(const vector<size_t>& answer);
void WriteError();
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  try {
    auto input_data = ReadData();
    auto result = Solution(input_data);
    WriteAnswer(result);
  } catch (...) {
    WriteError();
  }
  return 0;
}
vector<size_t> Solution(int64_t data) {
  vector<size_t> answer(2 * data);
  size_t n = data;
  for (size_t i = 0; i < n / 2; ++i) {
    answer[i] = answer[n - i - 1] = 2 * i + 1;
  }
  for (size_t i = n; i < n + n / 2; ++i) {
    answer[i] = answer[2 * n - (i - n) - 1] = 2 * (i - n + 1);
  }
  for (size_t idx = 0; idx < n * 2; ++idx) {
    if (answer[idx] == 0) {
      answer[idx] = n;
    }
  }
  return answer;
}
void WriteError() {}
int64_t ReadData() {
  int64_t q;
  cin >> q;
  return q;
}
void WriteAnswer(const vector<size_t>& answer) {
  for (auto it : answer) {
    cout << it << " ";
  }
}
