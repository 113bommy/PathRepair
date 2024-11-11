#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int r = 0, xa = 0, bx = 0, ba = 0;
  for (; n > 0; n--) {
    string s;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); i++) {
      r += s[i] == 'A' && s[i + 1] == 'B';
    }
    xa += s.back() == 'A';
    bx += s.front() == 'B';
    ba += s.back() == 'A' && s.front() == 'B';
  }
  cout << r + min(xa, bx) - (xa == ba && bx == ba) << endl;
}
