#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  int y;
  if (x.size() == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < x.size(); ++i) {
    y += x[i] - '0';
  }
  int ans = 1;
  while (y > 9) {
    string z = to_string(y);
    y = 0;
    for (int i = 0; i < z.size(); ++i) {
      y += z[i] - '0';
    }
    ++ans;
  }
  cout << ans;
  return 0;
}
