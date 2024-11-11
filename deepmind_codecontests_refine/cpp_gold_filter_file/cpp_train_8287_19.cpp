#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int out = 0;
  int flag = 1;
  for (int i = 0; i < n - 1; i++) {
    if (flag == 1) {
      if (a < b) {
        flag = 2;
        out += a;
      } else {
        flag = 3;
        out += b;
      }
    } else if (flag == 2) {
      if (c < a) {
        flag = 3;
        out += c;
      } else {
        flag = 1;
        out += a;
      }
    } else if (flag == 3) {
      if (b < c) {
        flag = 1;
        out += b;
      } else {
        flag = 2;
        out += c;
      }
    }
  }
  cout << out;
  return 0;
}
