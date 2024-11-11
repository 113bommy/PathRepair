#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  cin >> s1;
  int ans = 0;
  int x = 20;
  if (s1.length() == 1) {
    cout << 0 << endl;
    return 0;
  }
  while (x >= 10) {
    x = 0;
    for (int i = 0; i < s1.length(); i++) {
      x += (s1[i] - '0');
    }
    s1 = to_string(x);
    ans++;
  }
  cout << ans;
  return 0;
}
