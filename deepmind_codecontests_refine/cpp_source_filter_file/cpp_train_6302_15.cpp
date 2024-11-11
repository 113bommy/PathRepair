#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, tem;
  cin >> num;
  if (num <= 9)
    cout << num;
  else if (num <= (9 + 90 * 2)) {
    num -= 9;
    tem = num;
    num = ceil((double)num / 2) + 9;
    if (tem % 2 == 1)
      cout << (num / 10);
    else
      cout << (num % 10);
  } else {
    num = num - 9 - (90 * 2);
    tem = num;
    num = ceil((double)num / 3) + 9 + 90;
    if (tem % 3 == 1)
      cout << (num / 100);
    else if (num % 3 == 2)
      cout << (num % 100) / 10;
    else
      cout << (num % 10);
  }
  return 0;
}
