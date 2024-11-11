#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0, position = 0;
  int length = s.size();
  for (int i = 0; i < length; i++) {
    if (s[i] == 'R') {
      x1++;
      position++;
    }
    if (s[i] == 'L') {
      x1--;
      position--;
    }
    if (s[i] == 'U') {
      y1++;
      position++;
    }
    if (s[i] == 'D') {
      y1--;
      position--;
    }
  }
  if (length % 2 == 0) {
    printf("%d", (abs(x1) + abs(y2)) / 2);
  } else {
    cout << -1;
  }
}
