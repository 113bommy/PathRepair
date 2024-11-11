#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> str_arr = vector<string>();
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    str_arr.push_back(str);
  }
  for (int i = n - 1; i > 0; i--) {
    string a = str_arr[i];
    string b = str_arr[i - 1];
    int a_size = a.length();
    int b_size = b.length();
    if (a_size == 1) {
      str_arr[i - 1] = "#";
      continue;
    }
    int min_len = a_size > b_size ? b_size : a_size;
    bool sub = false;
    for (int j = 0; j < min_len; j++) {
      if (a[j] < b[j]) {
        b = b.substr(0, j);
        str_arr[i - 1] = b;
        sub = true;
        break;
      }
      if (a[j] != b[j]) {
        sub = true;
        break;
      }
    }
    if (!sub && b_size > a_size) {
      b = b.substr(0, min_len);
      str_arr[i - 1] = b;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << str_arr[i] << endl;
  }
  return 0;
}
