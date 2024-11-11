#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int len = str.length();
  int count1 = 0, count2 = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] >= 65 && str[i] <= 90)
      count1++;
    else
      count2++;
  }
  if (count1 <= count2)
    transform(str.begin(), str.end(), str.begin(), ::tolower);
  else
    transform(str.begin(), str.end(), str.begin(), ::toupper);
  cout << str;
}
