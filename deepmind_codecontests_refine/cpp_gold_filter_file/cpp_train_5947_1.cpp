#include <bits/stdc++.h>
using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::set;
using std::string;
using std::vector;
int main() {
  int n;
  string s;
  cin >> n >> s;
  string answer;
  for (int start = 0; start < n && answer.empty(); ++start) {
    int max = 0;
    int counts[26] = {0};
    for (int end = start; end < n && answer.empty(); ++end) {
      int i = s[end] - 'a';
      int candidate = ++counts[i];
      if (candidate > max) {
        max = candidate;
      }
      int length = end - start;
      if (max <= (length + 1) / 2) {
        answer = s.substr(start, length + 1);
      }
    }
  }
  if (answer.empty()) {
    cout << "NO";
  } else {
    cout << "YES\n" << answer;
  }
  cout << endl;
  return 0;
}
