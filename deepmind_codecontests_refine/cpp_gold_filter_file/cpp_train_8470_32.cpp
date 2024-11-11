#include <bits/stdc++.h>
using namespace std;
int number, temp;
int o(0), t(0), h(0), T(0);
void update() {
  o = number % 10;
  number = number / 10;
  t = number % 10;
  number = number / 10;
  h = number % 10;
  number = number / 10;
  T = number % 10;
}
int check() {
  bool flag = true;
  while (flag) {
    if (o == t || o == h || o == T) {
      temp++;
      number = temp;
      update();
    } else if (t == h || t == T) {
      temp += 1;
      number = temp;
      update();
    } else if (h == T) {
      temp += 1;
      number = temp;
      update();
    } else {
      flag = false;
    }
  }
  if (!flag) {
    return temp;
  }
}
int main() {
  cin >> number;
  number++;
  temp = number;
  o = number % 10;
  number = number / 10;
  t = number % 10;
  number = number / 10;
  h = number % 10;
  number = number / 10;
  T = number % 10;
  cout << check();
}
