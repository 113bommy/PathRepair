#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int dir[4] = {0, 0, 0, 0};
  if (n & 1) n = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L')
      dir[0]++;
    else if (s[i] == 'R')
      dir[1]++;
    else if (s[i] == 'U')
      dir[2]++;
    else
      dir[3]++;
  }
  if (n > 0) n = max(abs(dir[0] - dir[1]), abs(dir[2] - dir[3]));
  cout << n;
  return 0;
}
