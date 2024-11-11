#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.length(), seq = 0;
  long long int w = 1;
  bool flagn = false, flagu = false;
  int f[100001];
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < 100001; ++i) {
    f[i] = f[i - 1] + f[i - 2];
    f[i] %= 1000000007;
  }
  for (int i = 0; i < l; ++i) {
    if (s[i] == 'm' || s[i] == 'w') {
      cout << 0;
      return 0;
    }
    if (s[i] == 'n') {
      if (flagu) {
        w *= f[seq];
        w %= 1000000007;
        seq = 0;
        flagu = false;
      }
      flagn = true;
      seq++;
      continue;
    }
    if (s[i] == 'u') {
      if (flagn) {
        w *= f[seq];
        w %= 1000000007;
        seq = 0;
        flagn = false;
      }
      flagu = true;
      seq++;
      continue;
    }
    flagn = false;
    flagu = false;
    if (seq != 0) {
      w *= f[seq];
      w %= 1000000007;
    }
    seq = 0;
  }
  w *= f[seq];
  w %= 1000000007;
  cout << w;
  return 0;
}
