#include <bits/stdc++.h>
using namespace std;
string ans[10] = {"", "", "2", "3", "223", "5", "53", "7", "7222", "7332"};
int main() {
  int n;
  string s, a = "";
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' || s[i] == '1') continue;
    a += ans[(s[i] - '0')];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  cout << a << endl;
}
