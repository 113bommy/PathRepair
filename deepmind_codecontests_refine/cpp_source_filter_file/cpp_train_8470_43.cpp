#include <bits/stdc++.h>
using namespace std;
bool distinct(int year) {
  return ((year / 1000) != (year / 100 % 10) &&
          (year / 1000) != (year / 10 % 10) && (year / 1000) != (year % 10) &&
          (year / 100 % 10) != (year / 10 % 10) &&
          (year / 100 % 10) != (year % 10) && (year / 10 % 10) != (year % 10));
}
int main() {
  int year;
  cin >> year;
  int i, cont;
  cont = year;
  while (i != -1) {
    cont++;
    if (distinct(cont)) {
      i = -1;
    }
  }
  cout << cont << endl;
  return 0;
}
