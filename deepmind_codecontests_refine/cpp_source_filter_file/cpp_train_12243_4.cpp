#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  int h = 10 * (s[0] - '0') + (s[1] - '0');
  int m = 10 * (s[3] - '0') + (s[4] - '0');
  int t = 60 * h + m;
  for (int i = 0; i < 24; i++) {
    int j = 0;
    for (int k = i; k > 0; k /= 10) {
      j = 10 * j + k % 10;
    }
    if (j / 10 == 0) j *= 10;
    if (j >= 60) continue;
    if (60 * i + j >= t) {
      cout << 60 * i + j - t << '\n';
      return 0;
    }
  }
  cout << 24 * 60 - t << '\n';
  return 0;
}
