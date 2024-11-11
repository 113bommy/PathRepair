#include <bits/stdc++.h>
using namespace std;
string s;
int n4, n7;
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '4')
      n4++;
    else if (s[i] == '7')
      n7++;
  if (n4 == 0 && n7 == 0)
    cout << -1;
  else if (n7 < n4)
    cout << 7;
  else
    cout << 4;
  return 0;
}
