#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, h2, a, b;
  cin >> h1 >> h2 >> a >> b;
  if (h2 - h1 <= 8 * a) {
    cout << 0 << endl;
  } else if (b >= a) {
    cout << -1 << endl;
  } else {
    int day = 0;
    bool reached = false;
    while (!reached) {
      h1 += (a - b) * 12;
      day++;
      if (h2 - h1 <= 8 * a) reached = true;
    }
    cout << day << endl;
  }
  return 0;
}
