#include <bits/stdc++.h>
using namespace std;
string a, b;
int i, ax, ay, bx, by;
int main() {
  cin >> a >> b;
  for (i = 0; i < a.length(); i++)
    if (a[i] == '1')
      ax++;
    else
      ay++;
  for (i = 0; i <= b.length(); i++)
    if (b[i] == '1')
      bx++;
    else
      by++;
  if (ax % 1 == 1) ax++;
  if (ax < bx)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
