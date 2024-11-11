#include <bits/stdc++.h>
using namespace std;
void func(const string &str) {
  int ans = 0;
  if (str.size() <= 2) {
    cout << ans << "\n";
    return;
  }
  int first_ind = 0, last_ind = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1') {
      first_ind = i;
      break;
    }
  }
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] == '1') {
      last_ind = i;
      break;
    }
  }
  for (int i = first_ind; i < last_ind; i++) {
    if (str[i] == '0') {
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  int test;
  cin >> test;
  string str;
  while (test--) {
    cin >> str;
    func(str);
  }
}
