#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int _a = 0, _b = 1023;
  for (int i = 0; i < n; i++) {
    char a;
    int b;
    cin >> a >> b;
    if (a == '|') {
      _a |= b;
      _b |= b;
    }
    if (a == '&') {
      _a &= b;
      _b &= b;
    }
    if (a == '^') {
      _a ^= b;
      _b ^= b;
    }
  }
  cout << 2 << '\n';
  cout << "| " << ((_a ^ _b) ^ 1023) << '\n';
  cout << "^ " << (_b ^ 1023);
}
