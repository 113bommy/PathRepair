#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7, M = 5e1 + 1, OO = 0x3f3f3f3f, MOD = 1e9 + 7;
int main() {
  string s;
  char ch = '1';
  int n, x, y, op = 0;
  cin >> n >> x >> y >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' && ch == '1') op++;
    ch = s[i];
  }
  op ? cout << (--op) * min(x, y) + y : cout << 0;
  return 0;
}
