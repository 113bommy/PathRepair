#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  if (n & 1) {
    cout << -1 << endl;
    exit(0);
  }
  int u = 0;
  int d = 0;
  int l = 0;
  int r = 0;
  for (int i = 0; i < n; ++i) {
    u += s[i] == 'U';
    d += s[i] == 'D';
    l += s[i] == 'L';
    r += s[i] == 'R';
  }
  cout << (abs(r - l) + abs(u - d)) / 2 << endl;
  return 0;
}
