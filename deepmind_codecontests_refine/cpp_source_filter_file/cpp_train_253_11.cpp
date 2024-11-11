#include <bits/stdc++.h>
using namespace std;
long long g(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return g(b, a % b);
}
char s[100010];
int main() {
  int i, j, k, n, x, y, l, lst, op, cl, ans, op1, cl1, fl, hs;
  x = y = op = cl = op1 = cl1 = fl = hs = 0;
  cin >> s;
  l = strlen(s);
  for (i = 0; i < l; i++) {
    if (s[i] == '#') hs++;
  }
  for (i = l - 1; i >= 0; i--) {
    if (s[i] == '#') {
      lst = i;
      break;
    }
  }
  for (i = 0; i < lst; i++) {
    if (s[i] == '(')
      op++;
    else {
      cl++;
      if (cl > op) {
        fl = 1;
        break;
      }
    }
  }
  for (i = lst + 1; i < l; i++) {
    if (s[i] == '(')
      op1++;
    else
      cl1++;
  }
  ans = op + op1 - cl - cl1;
  if (ans <= 0 || ans > op) fl = 1;
  cl += ans;
  for (i = lst + 1; i < l; i++) {
    if (s[i] == '(')
      op++;
    else {
      cl++;
      if (cl > op) {
        fl = 1;
        break;
      }
    }
  }
  if (fl) {
    cout << "-1\n";
  } else {
    for (i = 1; i < hs; i++) cout << "1\n";
    cout << ans << "\n";
  }
  return 0;
}
