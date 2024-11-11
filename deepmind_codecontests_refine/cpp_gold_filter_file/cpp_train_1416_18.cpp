#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  double HH, MM;
  cin >> HH >> c >> MM;
  if (HH >= 12) HH -= 12;
  cout << HH * 30 + MM / 2 << " " << MM * 6 << endl;
}
