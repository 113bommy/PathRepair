#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool boy = false;
  int cg = 0, cb = 0, sum = 0, total = 0, j = 0, counter = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'F') {
      sum = i - counter;
      counter++;
      if (j > 0 && j + 1 == i && boy) {
        cg++;
      } else {
        if (cb > cg + 1 + total)
          total = 0;
        else {
          total += cg + 1 - cb;
        }
        cg = 0;
        cb = 0;
      }
      j = i;
    } else {
      boy = true;
      cb++;
    }
  }
  if (cg > 0) {
    total += cg;
  }
  printf("%d", sum + total);
  return 0;
}
