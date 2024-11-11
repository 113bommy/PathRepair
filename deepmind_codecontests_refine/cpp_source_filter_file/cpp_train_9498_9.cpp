#include <bits/stdc++.h>
using namespace std;
#pragma(comment, linker("\STACK:50000000"))
int rev(int x) {
  int ans = 0;
  for (int i = 0; i < 8; ++i) {
    ans = 2 * ans + x % 2;
    x /= 2;
  }
  return ans;
}
int main() {
  string s;
  getline(cin, s);
  vector<int> a((int)(s).size());
  for (int i = 0; i < (int)(s).size(); ++i) {
    a[i] = s[i];
  }
  int last = 0;
  for (int i = 0; i < (int)(a).size(); ++i) {
    int c = (i > 0 ? rev(a[i - 1]) : 0) - rev(a[i]);
    while (c < 0) c += 256;
    c %= 256;
    printf("%03d\n", c);
    last = rev(a[i]);
  }
}
