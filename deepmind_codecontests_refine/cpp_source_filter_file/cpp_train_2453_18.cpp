#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1;
  cin >> s >> s1;
  int a, a1;
  if (s == "monday") {
    a = 0;
  }
  if (s == "tuesday") {
    a = 1;
  }
  if (s == "wednesday") {
    a = 2;
  }
  if (s == "thursday") {
    a = 3;
  }
  if (s == "friday") {
    a = 4;
  }
  if (s == "saturday") {
    a = 5;
  }
  if (s == "sunday") {
    a = 6;
  }
  if (s1 == "monday") {
    a1 = 0;
  }
  if (s1 == "tuesday") {
    a1 = 1;
  }
  if (s1 == "wednesday") {
    a1 = 2;
  }
  if (s1 == "thursday") {
    a1 = 3;
  }
  if (s1 == "friday") {
    a1 = 4;
  }
  if (s1 == "saturday") {
    a1 = 5;
  }
  if (s1 == "sunday") {
    a1 = 6;
  }
  if ((a1 - a) % 7 <= 3 && (a1 - a) % 7 != 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
