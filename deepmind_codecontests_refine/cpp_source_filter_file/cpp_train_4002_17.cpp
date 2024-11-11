#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  getline(cin, str);
  bool flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
  if (str.length() >= 5) flag1 = 1;
  for (int i = 0; i < str.length(); i++) {
    int x = str[i] - '0';
    if (x <= 9 and x >= 0)
      flag4 = 1;
    else if (str[i] <= 'z' and str[i] >= 'a')
      flag3 = 1;
    else if (str[i] <= 'Z' and str[i] >= 'A')
      flag2 = 1;
  }
  if (flag1 and flag2 and flag3 and flag4)
    cout << "Correct\n";
  else
    cout << "To weak\n";
  return 0;
}
