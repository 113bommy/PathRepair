#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int cnt;
  char s[110];
  cin >> a >> s;
  int len = strlen(s);
  for (int i = len - 1; i >= len - 4; i--) {
    if (s[i] == 'e') {
      cnt = len - 1 - i;
      if (cnt == 3) {
        b = (s[i + 1] - '0') * 100 + (s[i + 2] - '0') * 10 +
            (s[i + 3] - '0') * 1;
        break;
      } else if (cnt == 2) {
        b = (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
        break;
      } else {
        b = s[i + 1] - '0';
        break;
      }
    }
  }
  int n;
  if (b == len - cnt - 2) {
    cout << a;
    n = 0;
    for (int i = len - cnt - 2;; i--) {
      if (s[i] == '0' || s[i] == '.')
        n++;
      else
        break;
    }
    for (int i = 1; i < len - cnt - 1 - n; i++) cout << s[i];
    cout << endl;
  } else if (b > len - cnt - 2) {
    int oo = b + 1 - (len - 1 - cnt);
    cout << a;
    for (int i = 1; i < len - cnt - 1 - n; i++) cout << s[i];
    for (int i = 0; i < oo; i++) cout << 0;
    cout << endl;
  } else {
    for (int i = 0; i < b; i++) {
      s[i] = s[i + 1];
    }
    s[b] = '.';
    cout << a;
    n = 0;
    for (int i = len - cnt - 2;; i--) {
      if (s[i] == '0' || s[i] == '.')
        n++;
      else
        break;
    }
    for (int i = 0; i < len - cnt - 1 - n; i++) cout << s[i];
    cout << endl;
  }
  return 0;
}
