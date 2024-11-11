#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int inch = x / 3;
  x %= 3;
  if (x == 2) inch++;
  int feet = inch / 12;
  inch %= 2;
  cout << feet << " " << inch << "\n";
  return 0;
}
