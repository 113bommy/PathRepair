#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int len, i, cnt = 0, B, u, l, b, a, s, r;
  cin >> str;
  len = str.size();
  B = u = l = b = a = s = r = 0;
  for (i = 0; i < len; i++) {
    if (str[i] == 'B') B++;
    if (str[i] == 'u') u++;
    if (str[i] == 'l') l++;
    if (str[i] == 'b') b++;
    if (str[i] == 'a') a++;
    if (str[i] == 's') s++;
    if (str[i] == 'r') r++;
  }
  if (u <= 1) {
    cout << 0 << endl;
    return 0;
  } else
    u = u / 2;
  if (a <= 1) {
    cout << 0 << endl;
    return 0;
  } else
    a = a / 2;
  cnt = min(B, u);
  cnt = min(cnt, l);
  cnt = min(cnt, b);
  cnt = min(cnt, a);
  cnt = min(cnt, s);
  cnt = min(cnt, r);
  cout << cnt << endl;
  return 0;
}
