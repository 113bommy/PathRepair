#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int a, b, c, mx, mn, k = 1, cnt = 0;
  cin >> a >> b >> c >> s;
  if (b > a) swap(a, b);
  for (int i = 0; i < a; i++) {
    if (s[i] == '*') {
      if (b > a) swap(a, b);
      k = 1;
    } else {
      if (k % 2 && a) {
        a--;
        cnt++;
      } else if (b) {
        b--;
        cnt++;
      }
      k++;
    }
  }
  cout << cnt << endl;
}
