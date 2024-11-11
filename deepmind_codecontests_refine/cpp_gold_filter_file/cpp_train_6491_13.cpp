#include <bits/stdc++.h>
using namespace std;
long long y, c = 1, s[20];
string a;
int main() {
  cin >> a >> y;
  for (int i = 0; i < a.size(); i++) s[i] = a[i] - '0';
  for (int i = a.size() - 1; i > 0; i--) {
    if (s[i] == 9) {
      c *= 10;
      continue;
    }
    if (y - (s[i] + 1) * c >= 0) {
      y -= ((s[i] + 1) * c);
      s[i] = 9;
      c *= 10;
    } else
      break;
    for (int j = i - 1; j > -1; j--) {
      if (!s[j])
        s[j] = 9;
      else {
        s[j] -= 1;
        break;
      }
    }
  }
  bool f = false;
  for (int i = 0; i < a.size(); i++) {
    if (f)
      printf("%d", s[i]);
    else if (s[i]) {
      f = 1;
      printf("%d", s[i]);
    }
  }
  return 0;
}
