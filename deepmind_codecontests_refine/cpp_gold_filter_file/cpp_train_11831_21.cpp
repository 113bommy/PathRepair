#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int res = 0;
  string t = "aeiou13579";
  for (int i = 0; i < s.length(); i++)
    if (t.find(s[i]) != string::npos) res++;
  cout << res << endl;
  return 0;
}
