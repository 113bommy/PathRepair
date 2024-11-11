#include <bits/stdc++.h>
using namespace std;
int f(unsigned char n) {
  int s = 0;
  for (int i = 0; i < 8; i++) {
    if (n & (1 << i)) {
      s |= 1 << (7 - i);
    }
  }
  return s;
}
int main() {
  char str[200];
  cin >> str;
  int pre;
  for (int i = 0; str[i]; i++) {
    if (i == 0) pre = 0;
    int ans = f((unsigned)str[i]);
    if (pre - ans < 0) {
      cout << 256 + pre - ans << endl;
    } else {
      cout << (pre - ans) % 256 << endl;
    }
    pre = ans;
  }
  return 0;
}
