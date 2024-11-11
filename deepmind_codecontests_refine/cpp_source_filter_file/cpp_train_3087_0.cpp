#include <bits/stdc++.h>
using namespace std;
string t(string s, int i) {
  string sprime = "";
  for (int j = 0; j < i; j++) sprime += s[j];
  for (int j = i + 1; j < s.size(); j++) sprime += s[j];
  return sprime;
}
int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.size() - 1; i++)
    if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'e' ||
        s[i] == 'u' || s[i] == 'y')
      if (s[i + 1] == 'a' || s[i + 1] == 'o' || s[i + 1] == 'i' ||
          s[i + 1] == 'e' || s[i + 1] == 'u' || s[i] == 'y') {
        s = t(s, i + 1);
        i--;
      }
  cout << s << endl;
}
