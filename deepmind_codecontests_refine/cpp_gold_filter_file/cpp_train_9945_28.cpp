#include <bits/stdc++.h>
using namespace std;
char s[4], t[4];
int n, j, k, is_one_of, is;
string a, b;
int main() {
  cin >> s[0] >> s[1] >> s[3] >> s[2];
  cin >> t[0] >> t[1] >> t[3] >> t[2];
  for (int i = 0; i < 4; i++)
    if (s[i] != 'X') a += s[i];
  for (int i = 0; i < 4; i++)
    if (t[i] != 'X') b += t[i];
  for (int i = 0; i < 3; i++) {
    is_one_of = 1;
    k = 0;
    for (k = 0, j = i; k < 3; k++, j = (j + 1) % 3)
      if (a[k] != b[j]) is_one_of = 0;
    if (!is) is = is_one_of;
  }
  if (is)
    cout << "YES\n" << endl;
  else
    cout << "NO\n" << endl;
}
