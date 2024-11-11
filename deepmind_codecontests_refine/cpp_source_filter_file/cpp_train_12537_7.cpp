#include <bits/stdc++.h>
using namespace std;
int tmp, t;
int main() {
  char s[10000], c;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.')
      t++;
    else if (s[i] == 'R') {
      tmp += t;
      t = 0;
      c = s[i];
    } else {
      if (c == 'R') tmp += t % 2;
      t = 0;
      c = s[i];
    }
  }
  if (c == 'L') tmp += t;
  cout << tmp;
}
