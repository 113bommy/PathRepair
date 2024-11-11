#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a_count = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'a') {
      a_count++;
    }
  }
  if (a_count > s.length() / 2) {
    cout << s.length() << endl;
    return 0;
  }
  int req_len = a_count * 2 - 1;
  cout << req_len << endl;
  return 0;
}
