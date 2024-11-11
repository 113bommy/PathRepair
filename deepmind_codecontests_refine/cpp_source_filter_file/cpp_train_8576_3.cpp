#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, a, b;
  cin >> num;
  if (num >= 0)
    cout << num;
  else {
    num *= -1;
    a = (num / 10);
    b = (num / 100) * 100 + num % 10;
    if (b < a)
      num = b;
    else
      num = a;
    num *= -1;
    cout << num;
  }
  return 0;
}
