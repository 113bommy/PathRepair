#include <bits/stdc++.h>
using namespace std;
bool isdistinct(string s) {
  int arr[200] = {0};
  for (int i = 0; i < s.length(); i++) {
    if (arr[s[i]] != 0) return false;
    arr[s[i]] = 1;
  }
  return true;
}
int main() {
  int y;
  cin >> y;
  for (int i = y + 1; i <= 9000; i++) {
    string s = to_string(i);
    if (isdistinct(s)) {
      cout << s << endl;
      break;
    }
  }
}
