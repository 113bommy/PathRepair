#include <bits/stdc++.h>
using namespace std;
int xuli() {
  string s;
  cin >> s;
  for (int i = 1; i < s.size(); i++)
    if (s[i] >= 97) {
      for (int i = 0; i < s.size(); i++) cout << s[i];
      return 0;
    }
  if (s[0] >= 97)
    s[0] -= 32;
  else
    s[0] += 32;
  for (int i = 1; i < s.size(); i++)
    if (s[i] < 97) s[i] += 32;
  for (int i = 0; i < s.size(); i++) cout << s[i];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  xuli();
}
