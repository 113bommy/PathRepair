#include <bits/stdc++.h>
using namespace std;
void solution() {
  string str;
  cin >> str;
  int hour = (str[0] - 48) * 10 + str[1] - 48;
  int minutes = (str[3] - 48) * 10 + (str[4] - 48);
  if (hour == 6 or hour == 7 or hour == 8 or hour == 9) {
    cout << "10:01";
    return;
  }
  if (hour == 19 or hour == 15 or hour == 16 or hour == 17 or hour == 18) {
    cout << "20:02";
    return;
  }
  if (minutes < (str[1] - 48) * 10 + str[0] - 48) {
    cout << str[0] << str[1] << ":" << str[1] << str[0];
    return;
  }
  if (hour == 23) {
    std::cout << "00:00" << std::endl;
    return;
  }
  cout << str[0] << str[1] - 47 << ":" << str[1] - 47 << str[0];
  return;
}
int main() {
  solution();
  return 0;
}
