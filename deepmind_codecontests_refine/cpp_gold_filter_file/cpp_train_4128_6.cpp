#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t = 0, o = 0;
  cin >> n;
  float r;
  for (int i = n; i > 2; i--) {
    r = (i + 1) / 2 + 1;
    if (r - (int)r != 0) r = (int)r + 1;
    for (int j = i - 1; j > r; j--) {
      for (int y = j - 1; y > i - j; y--) {
        if (i < j + y) {
          if (((i ^ j) ^ y) == 0) {
            t++;
            o = 1;
            break;
          }
        } else {
          break;
        }
      }
      if (o == 1) {
        o = 0;
        continue;
      }
    }
  }
  cout << t;
}
