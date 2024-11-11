#include <bits/stdc++.h>
using namespace std;
bool is_alpha(char c) {
  if (c >= 'a' && c <= 'z') return true;
  return false;
}
int main() {
  string str;
  double sum = 0;
  int d = 0, f = 0;
  cin >> str;
  int len = str.length();
  for (int i = 0; i < len; ++i) {
    if (is_alpha(str[i])) {
      sum += d + f / 100.0;
      d = 0, f = 0;
    } else if (str[i] == '.') {
      if (i + 3 >= len) {
        for (int j = i + 1; j < i + 3; ++j) {
          f = f * 10 + str[j] - '0';
        }
        break;
      } else if (isalpha(str[i + 3])) {
        for (int j = i + 1; j < i + 3; ++j) {
          f = f * 10 + str[j] - '0';
        }
        i += 2;
      } else if (str[i + 3] >= '0' && str[i + 3] <= '9') {
        continue;
      }
    } else {
      d = d * 10 + str[i] - '0';
    }
  }
  sum += d + f / 100.0;
  int dd = floor(sum);
  stringstream ss;
  ss << dd;
  string s = ss.str();
  double ff = sum - floor(sum);
  int t = int(ff * 100 + 1e-3);
  int cnt = 0;
  for (int i = s.length() - 1; i >= 0; --i) {
    ++cnt;
    if (cnt == 3 && i != 0) {
      s.insert(i, 1, '.');
      cnt = 0;
    }
  }
  cout << s;
  if (t) printf(".%02d", t);
}
