#include <bits/stdc++.h>
using namespace std;
int s[4], r;
int main() {
  cin >> s[0] >> s[1] >> s[2] >> s[3];
  sort(s, s + 4);
  r = max(s[0] + s[1] - s[2], s[0] + s[1] - s[3]);
  if (r > 0)
    cout << "TRIANGLE" << endl;
  else if (r < 0)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << "SEGMENT" << endl;
  return 0;
}
