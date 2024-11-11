#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int vt, i, j, t = 0, p = 0, d1 = 0, d2 = 0;
  vt = s.find("^");
  for (int i = 0; i < vt; i++)
    if (s[i] != '=') t += (s[i] - '0') * (vt - i);
  for (int i = vt + 1; i < s.size(); i++)
    if (s[i] != '=') p += (s[i] - '0') * (i - vt);
  if (t == p)
    cout << "balance";
  else if (t < p)
    cout << "right";
  else
    cout << "left";
}
