#include <bits/stdc++.h>
using namespace std;
int n, pl, mi, rsp, i, ok, semn;
string s;
int abs(int a) {
  if (a > 0) return a;
  return -a;
}
int main() {
  getline(cin, s);
  pl++;
  for (i = 0; i < s.size() && s[i] != '='; i++)
    if (s[i] == '+')
      pl++;
    else if (s[i] == '-')
      mi++;
  for (; i < s.size(); i++)
    if (isdigit(s[i])) n = n * 10 + s[i] - '0';
  if (n < pl * n - mi && n > -n * mi + pl) {
    cout << "Possible\n";
    int S = 0;
    ok = 1;
    semn = 1;
    pl--;
    for (int i = 0; i < s.size() && s[i + 2] != '='; i++) {
      if (i > 1 && s[i - 2] == '-')
        semn = -1, mi--, ok = 1, i++;
      else if (i > 1 && s[i - 2] == '+')
        semn = 1, pl--, ok = 1, i++;
      if (ok == 0) {
        cout << s[i];
        continue;
      }
      for (int x = 1; x <= n; x++)
        if (n <= S + semn * x + n * pl - mi &&
            n >= S + semn * x - n * mi + pl) {
          S += semn * x;
          cout << x << " ";
          break;
        }
      ok = 0;
    }
    cout << abs(n - S) << " = " << n;
  } else
    cout << "Impossible";
  return 0;
}
