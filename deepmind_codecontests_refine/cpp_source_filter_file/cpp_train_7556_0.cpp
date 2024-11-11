#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, t, count, sum, i, flag;
  while (cin >> y) {
    sum = 1;
    count = 0;
    t = y;
    while (t) {
      t = t / 10;
      count++;
    }
    if (count != 1) {
      count--;
      for (i = 0; i < count; i++) sum = sum * 10;
      t = y / sum;
      t++;
      cout << t * sum - y << endl;
    } else
      cout << y + 1 << endl;
  }
  return 0;
}
