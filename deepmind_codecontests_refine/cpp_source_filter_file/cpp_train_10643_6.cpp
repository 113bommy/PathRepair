#include <bits/stdc++.h>
using namespace std;
int calc(int x) {
  int res = 0;
  for (int i = 0; i < 8; ++i) {
    res = res * 2 + x % 2;
    x /= 2;
  }
  return res;
}
string s;
int main() {
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    int tmp = 0;
    if (i > 0) tmp = calc(s[i - 1]);
    printf("%d\n", (calc(tmp) - calc((int)s[i]) + 256 * 256) % 256);
  }
  return 0;
}
