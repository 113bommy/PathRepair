#include <bits/stdc++.h>
using namespace std;
string s;
void fun() {
  int min = 10 * (s[3] - '0') + (s[4] - '0');
  int hr = 10 * (s[0] - '0') + (s[1] - '0');
  min++;
  if (min < 60) {
    s[3] = (min / 10) + '0';
    s[4] = (min % 10) + '0';
    return;
  } else
    s[3] = s[4] = '0';
  hr++;
  if (hr == 24)
    s[0] = s[1] = '0';
  else {
    s[0] = (hr / 10) + '0';
    s[1] = (hr % 10) + '0';
  }
}
int main() {
  int i = 0;
  cin >> s;
  while (1) {
    if (s[0] == s[4] && s[1] == s[3]) break;
    fun();
    i++;
  }
  cout << i;
  return 0;
}
