#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, x = 1, meals = 1, distance = 0;
  cin >> n;
  cin >> a;
  cin >> b;
  cin >> c;
  while (meals < n) {
    if (x == 1) {
      if (a < b) {
        x = 2;
        meals++;
        distance = distance + a;
      } else {
        x = 3;
        meals++;
        distance = distance + b;
      }
    } else if (x == 2) {
      if (a < c) {
        x = 1;
        meals++;
        distance = distance + a;
      } else {
        x = 3;
        meals++;
        distance = distance + c;
      }
    } else if (x == 3) {
      if (b < c) {
        x = 1;
        meals++;
        distance = distance + b;
      } else {
        x = 2;
        meals++;
        distance = distance + c;
      }
    }
  }
  cout << distance << endl;
}
