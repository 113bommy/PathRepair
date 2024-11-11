#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int ans = 0;
  cin >> str;
  for (int i = 0; i < str.size() - 1; i++) {
    int lst = (str[i] - '0') * 10 + (str[i + 1] - '0');
    if (lst % 4 == 0) {
      ans += i + 1;
    }
    if (lst % 10 % 4 == 0) {
      ans += 1;
    }
  }
  if ((str[0] - '0') % 4 == 0) {
    ans += 1;
  }
  cout << ans;
}
