#include <bits/stdc++.h>
using namespace std;
int i, t, t2, n, HP, a[2], b[2];
char s[100100];
int main() {
  scanf("%s", s);
  n = strlen(s);
  a[0] = 0;
  a[1] = 0;
  HP = 0;
  for (i = 0; i < n; ++i) {
    if (s[i] != '?')
      ++a[s[i] - '0'];
    else
      ++HP;
  }
  if (n % 2 == 0 && a[0] + HP - a[1] >= 2)
    cout << "00" << endl;
  else if (n % 2 == 1 && a[0] + HP - a[1] >= 1)
    cout << "00" << endl;
  t = (n >> 1) - a[0];
  t2 = HP - t;
  if (HP + a[0] >= (n >> 1) && a[0] <= (n >> 1))
    if (s[n - 1] == '1' || (s[n - 1] == '?' && t2 > 0)) cout << "01" << endl;
  if (HP + a[0] >= (n >> 1) && a[0] <= (n >> 1))
    if (s[n - 1] == '0' || (s[n - 1] == '?' && t > 0)) cout << "10" << endl;
  if (n == 2 && a[1] + HP == 2 && a[0] == 0)
    cout << "11" << endl;
  else if (n % 2 == 0 && a[1] + HP - a[0] >= 3)
    cout << "11" << endl;
  else if (n % 2 == 1 && a[1] + HP - a[0] >= 1)
    cout << "11" << endl;
  return 0;
}
