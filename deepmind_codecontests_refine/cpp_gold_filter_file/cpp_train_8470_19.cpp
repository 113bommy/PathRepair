#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int temp = 0;
  deque<int> year;
  int c = 0;
  for (int y = n + 1; y <= 9015; y++) {
    int yy = y;
    for (int i = 0; i < 4; ++i) {
      temp = yy % 10;
      year.push_front(temp);
      yy /= 10;
    }
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 4; j++) {
        if (year[j] == i) {
          c++;
          break;
        }
      }
    }
    if (c == 4) {
      for (auto no : year) cout << no;
      return 0;
    }
    year.clear();
    c = 0;
  }
}
