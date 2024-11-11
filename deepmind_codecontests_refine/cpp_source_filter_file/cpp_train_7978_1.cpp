#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char ch[n + 1];
  cin >> ch;
  int x2 = 0, y2 = 0;
  int x1, y1;
  int x, y;
  if (n >= 3) {
    cout << "0";
    return 0;
  }
  if (ch[0] == 'R') {
    x1 = x2 + 1;
    y1 = y2;
  } else {
    x1 = x2;
    y1 = x2 + 1;
  }
  if (ch[1] == 'R') {
    x = x1 + 1;
    y = y1;
  } else {
    x = x1;
    y = y1 + 1;
  }
  int count = 0;
  for (int i = 2; i < n; i++) {
    x2 = x1;
    y2 = y1;
    x1 = x;
    y1 = y;
    if (ch[i] == 'R') {
      ++x;
      if (x == x2 + 2 && y == y2 && x1 == y1) {
        count++;
      }
    } else {
      ++y;
      if (x == x2 && y == y2 + 2 && x1 == y1) {
        count++;
      }
    }
  }
  cout << count;
}
