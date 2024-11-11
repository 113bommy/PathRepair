#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long x, y;
  int n;
  cin >> n >> x >> y >> s;
  int i0 = 0, i1 = 0;
  char on = 0;
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (*it != on) {
      if (*it == '0') {
        ++i0;
        on = '0';
      } else {
        ++i1;
        on = '1';
      }
    }
  }
  long long sum = 0;
  if (i0 == 0) {
    cout << 0 << endl;
  } else {
    sum = y;
    sum += (i0 - 1) * min(x, y);
    cout << sum << endl;
  }
}
