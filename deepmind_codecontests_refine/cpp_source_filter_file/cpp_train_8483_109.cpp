#include <bits/stdc++.h>
using namespace std;
int main() {
  int red, blue, fashionable_days = 0, same_color;
  cin >> red >> blue;
  while (red > 0 and blue > 0) {
    red -= 1, blue -= 1;
    fashionable_days += 1;
  }
  if (red == 0 and blue > 0) {
    same_color = blue / 2;
  } else if (red > 0 and blue == 0) {
    same_color = red / 2;
  }
  cout << fashionable_days << ' ' << same_color << endl;
}
