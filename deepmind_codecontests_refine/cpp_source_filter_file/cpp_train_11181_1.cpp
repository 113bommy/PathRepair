#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, tmp, Cost[1000][1000], i, j, k, sum = 0;
  char x, y;
  string s, t, res;
  cin >> s >> t;
  cin >> n;
  for (i = 97; i <= 122; i++) {
    for (j = 97; j <= 122; j++)
      if (i != j)
        Cost[i][j] = 100000;
      else
        Cost[i][j] = 0;
  }
  for (i = 1; i <= n; i++) {
    cin >> x >> y >> d;
    if (d < Cost[int(x)][int(y)]) Cost[int(x)][int(y)] = d;
  }
  if (s.length() != t.length())
    cout << -1;
  else {
    for (i = 97; i <= 122; i++)
      for (k = 97; k <= 122; k++)
        for (j = 97; j <= 122; j++) {
          Cost[i][j] = min(Cost[i][k] + Cost[k][j], Cost[i][j]);
        }
    for (i = 0; i < s.length(); i++) {
      if (s[i] != t[i]) {
        tmp = 100000;
        for (k = 97; k <= 122; k++) {
          if (tmp > Cost[int(s[i])][k] + Cost[int(t[i])][k]) {
            tmp = Cost[int(s[i])][k] + Cost[int(t[i])][k];
            x = char(k);
          }
        }
        if (tmp == 100000) {
          cout << -1;
          return 0;
        } else
          sum = sum + tmp;
        res = res + x;
      } else
        res = res + s[i];
    }
    cout << sum;
    cout << "\n" << res;
  }
}
