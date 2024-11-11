#include <bits/stdc++.h>
using namespace std;
int64_t power(int64_t a, int64_t b) { return (!b) ? 1 : a * power(a, b - 1); }
int main() {
  int n;
  int64_t t = 0;
  cin >> n;
  string s;
  cin >> s;
  int i = -1;
  for (int x = s.length() - 1; x >= 1; x--) {
    if (s[x] == 'B') {
      i = x;
      break;
    }
  }
  if (i == -1) {
    cout << 0 << endl;
    return 0;
  }
  s = s.substr(0, i + 1);
  int tmp = 0;
  for (int x = 0; x < s.length(); x++) {
    if (s[x] == 'B') {
      t++;
      t += power(2, x) - 1;
    }
  }
  cout << t << endl;
}
