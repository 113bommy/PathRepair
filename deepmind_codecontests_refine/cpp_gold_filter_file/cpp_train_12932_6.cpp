#include <bits/stdc++.h>
using namespace std;
bool is_in_board[26] = {false};
int main() {
  istream &data_stream = cin;
  int case_num;
  data_stream >> case_num;
  for (int j = 0; j < case_num; j++) {
    fill(is_in_board, is_in_board + 26, false);
    string str;
    data_stream >> str;
    deque<char> key_board;
    key_board.push_back(str[0]);
    is_in_board[str[0] - 'a'] = true;
    auto key_i = 0;
    int i = 1;
    for (i = 1; i < str.size(); i++) {
      if (key_i > 0 && key_board[key_i - 1] == str[i]) {
        key_i--;
        continue;
      }
      if (key_i + 1 < key_board.size() && key_board[key_i + 1] == str[i]) {
        key_i++;
        continue;
      }
      if (is_in_board[str[i] - 'a']) {
        break;
      }
      if (key_i == key_board.size() - 1) {
        key_board.push_back(str[i]);
        key_i++;
        is_in_board[str[i] - 'a'] = true;
        continue;
      }
      if (key_i == 0) {
        key_board.push_front(str[i]);
        is_in_board[str[i] - 'a'] = true;
        continue;
      }
      break;
    }
    if (i == str.size()) {
      string ans(key_board.begin(), key_board.end());
      for (int k = 0; k < 26; k++) {
        if (!is_in_board[k]) {
          ans.append(1, 'a' + k);
        }
      }
      printf("YES\n%s\n", ans.c_str());
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
