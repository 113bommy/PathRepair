#include <bits/stdc++.h>
using namespace std;
string s, ans = "";
int x;
char small(char c) { return (c <= 'Z' ? c + 32 : c); }
int main() {
  getline(cin, s);
  scanf("%d", &x);
  for (int i = 0; i < s.length(); i++)
    if ((int)(small(s[i]) - 'a') < x)
      ans += (char)(small(s[i]) - 32);
    else
      ans += small(s[i]);
  cout << ans << endl;
  return 0;
}
