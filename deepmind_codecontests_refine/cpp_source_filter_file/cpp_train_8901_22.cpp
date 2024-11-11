#include <bits/stdc++.h>
int fun(int x) {
  if (x == 2 || x == 3 | x == 5 || x == 11 || x == 13 || x == 14)
    return 5;
  else if (x == 1)
    return 2;
  else if (x == 4 || x == 12 || x == 15)
    return 4;
  else if (x == 6 || x == 9 || x == 0)
    return 6;
  else if (x == 7)
    return 3;
  else if (x == 8)
    return 8;
  else if (x == 10)
    return 6;
}
int fun1(int x) {
  int count = 0;
  while (x > 0) {
    count += fun(x % 10);
    x /= 10;
  }
  return count;
}
using namespace std;
int main() {
  int a, b, count = 0;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    count += fun1(i);
  }
  cout << count << endl;
}
