#include <bits/stdc++.h>
using namespace std;
long repeated_squaring(long base, long exp) {
  long result = 1;
  while (exp) {
    if (exp % 2) {
      result *= base;
    }
    base *= base;
    exp = exp >> 1;
  }
  return result;
}
vector<int> int_to_vector(long long num) {
  vector<int> v;
  while (1) {
    if (num == 0) {
      return v;
    }
    v.insert(v.begin(), num % 10);
    num /= 10;
  }
}
string replace_all(const string& message, const string& pattern,
                   const string& replace) {
  string result = message;
  string::size_type pos = 0;
  string::size_type offset = 0;
  int p_len = pattern.length();
  int r_len = replace.length();
  while ((pos = result.find(pattern, offset)) != string::npos) {
    result.replace(result.begin() + pos, result.begin() + pos + p_len, replace);
    offset = pos + r_len;
  }
  return result;
}
int main() {
  ios::sync_with_stdio(false);
  string str;
  int i, j, num, result = 0;
  long long val;
  vector<vector<int>> adj;
  int arr[4];
  int hour, min;
  cin >> num;
  cin >> hour >> min;
  while (1) {
    str = to_string(min) + to_string(hour);
    if (strchr(str.c_str(), '7')) {
      cout << result << "\n";
      return 0;
    }
    min -= 3;
    result++;
    if (min < 0) {
      min = 60 + min;
      hour -= 1;
      if (hour < 0) {
        hour = 23;
      }
    }
  }
  return 0;
}
