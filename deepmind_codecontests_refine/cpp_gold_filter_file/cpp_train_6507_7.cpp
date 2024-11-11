#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> str_list;
  string str;
  int max_length = 0, left_more = 0;
  while (getline(cin, str)) {
    max_length = max((int)str.size(), max_length);
    str_list.push_back(str);
  }
  cout << string(max_length + 2, '*') << endl;
  for (auto s : str_list) {
    int n = max_length - (int)s.size();
    int left = 0, right = 0;
    if (n % 2 == 0 || s.find_first_not_of(" ") == string::npos) {
      left = right = n / 2;
      right = n - left;
    } else {
      left = (n + left_more) / 2;
      right = n - left;
      left_more = 1 - left_more;
    }
    cout << '*' << string(left, ' ') << s << string(right, ' ') << '*' << endl;
  }
  cout << string(max_length + 2, '*') << endl;
}
