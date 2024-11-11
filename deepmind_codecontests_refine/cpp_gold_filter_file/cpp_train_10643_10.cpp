#include <bits/stdc++.h>
using namespace std;
int rev(int x) {
  bool bit[10];
  for (int i = 0; i < 8; ++i) bit[i] = (x >> i) & 1;
  int mul = 1, ans = 0;
  for (int i = 7; i >= 0; --i) {
    if (bit[i]) ans += mul;
    mul *= 2;
  }
  return ans;
}
int main() {
  string s;
  getline(cin, s);
  int last = 0;
  for (int i = 0; i < s.size(); ++i) {
    int tmp = rev(last), x = rev(int(s[i])), a;
    if (tmp >= x)
      a = tmp - x;
    else
      a = 256 + tmp - x;
    cout << a << endl;
    last = int(s[i]);
  }
  return 0;
}
