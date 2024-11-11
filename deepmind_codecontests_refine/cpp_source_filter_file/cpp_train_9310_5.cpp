#include <bits/stdc++.h>
using namespace std;
int n, i, k;
string s;
int main() {
  cin >> s;
  for (k = 1; k < s.length() - 2; k++)
    if (s[k] == 'd' && s[k + 1] == 'o' && s[k + 2] == 't') {
      s.insert(k, ".");
      s.erase(k + 1, 3);
    }
  for (k = 1; k < s.length() - 1; k++)
    if (s[k] == 'a' && s[k + 1] == 't') {
      s.insert(k, "@");
      s.erase(k + 1, 2);
      break;
    }
  cout << s << endl;
}
