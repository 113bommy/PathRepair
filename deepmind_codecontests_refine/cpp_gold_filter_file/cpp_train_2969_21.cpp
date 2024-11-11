#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  int res = 0;
  string str;
  cin >> num;
  cin >> str;
  cin >> str;
  if (str == "month") {
    if (num == 31)
      res = 7;
    else if (num == 30)
      res = 11;
    else
      res = 12;
  } else if (str == "week") {
    if (num == 5 || num == 6)
      res = 53;
    else
      res = 52;
  }
  cout << res;
  return 0;
}
