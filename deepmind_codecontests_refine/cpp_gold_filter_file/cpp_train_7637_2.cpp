#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ch = 0;
  int res = 0;
  cin >> ch;
  res = ch;
  for (int i = 1, h; i < n; ++i) {
    cin >> h;
    res += 1 + abs(ch - h);
    ch = h;
  }
  cout << (res + n);
  return 0;
}
