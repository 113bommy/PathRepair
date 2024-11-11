#include <bits/stdc++.h>
using namespace std;
string s;
int ar[100002];
int main() {
  int n, i, j, l = 0, r = 0, sum = 0, ok = 1, now = 0, f = -1, sum1 = 0,
               ok1 = 0;
  cin >> s;
  int len = s.size();
  for (i = len - 1; i >= 0; i--) {
    if (s[i] == '#') {
      f = i;
      break;
    }
  }
  for (i = 0; i <= f; i++) {
    if (s[i] == '(')
      l++, sum++;
    else if (s[i] == ')') {
      if (sum <= 0) {
        ok = 0;
        break;
      }
      r++;
      sum--;
    } else if (s[i] == '#') {
      if (sum >= 1) {
        ar[++now] = 1;
        r++;
        sum--;
      } else {
        ok = 0;
        break;
      }
    }
  }
  for (i = len - 1; 1; i--) {
    if (s[i] == '#') {
      f = i;
      break;
    }
  }
  sum1 = 0;
  if (f != -1) {
    for (i = f + 1; i < len; i++) {
      if (s[i] == '(')
        sum1++, ok1++;
      else {
        sum1--;
        if (ok1 > 0) ok1--;
      }
    }
    sum++;
    if (ok1 >= 1) ok = 0;
    if (sum + sum1 <= 0)
      ok = 0;
    else
      ar[now] = sum + sum1;
  }
  if (ok) {
    for (i = 1; i <= now; i++) cout << ar[i] << endl;
  } else
    cout << -1 << endl;
  return 0;
}
