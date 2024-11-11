#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, c, t, g;
  string s;
  int mini = 1000;
  cin >> n >> s;
  for (int i = 0; i <= n - 4; i++) {
    a = min(abs(s[i] - 65), abs(26 - abs(65 - s[i])));
    c = min(abs(s[i + 1] - 67), abs(26 - abs(67 - s[i + 1])));
    t = min(abs(s[i + 2] - 84), abs(26 - abs(84 - s[i + 2])));
    g = min(abs(s[i + 3] - 71), abs(26 - abs(71 - s[i + 3])));
    if ((abs(a) + abs(c) + abs(t) + abs(g)) < mini)
      mini = abs(a) + abs(c) + abs(t) + abs(g);
  }
  cout << mini;
  return 0;
}
