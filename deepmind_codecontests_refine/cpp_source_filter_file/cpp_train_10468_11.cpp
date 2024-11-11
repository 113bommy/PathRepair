#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
  string s;
  cin >> s;
  char t = s[0];
  int x = s[1] - 48;
  if (t - 1 < 'a' || t + 1 > 'h' && x - 1 < 1 || x + 1 > 8) {
    cout << 3;
    return 0;
  } else if (t - 1 < 'a' || t + 1 > 'h') {
    cout << 5;
    return 0;
  } else if (x - 1 < 1 || x + 1 > 8) {
    cout << 5;
    return 0;
  } else {
    cout << 8;
  }
}
