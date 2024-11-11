#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int nb = 0;
  for (int i = 0; i < (int)s.size(); i++)
    if ((s[i] == '4') || (s[i] == '7')) nb++;
  if ((nb == 7) || (nb == 4))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
