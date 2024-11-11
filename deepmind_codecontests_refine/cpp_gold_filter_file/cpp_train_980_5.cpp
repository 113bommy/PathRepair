#include <bits/stdc++.h>
using namespace std;
string s, s1;
int a[500], i, j, k, l, m, n;
int main() {
  cin >> s;
  cin >> s1;
  for (int i = 0; i < s.size(); i += 2) {
    if (s[i] == '8' && s[i + 1] == '<')
      if (s1[i] == '(' && s1[i + 1] == ')') k--;
    if (s[i] == '8' && s[i + 1] == '<')
      if (s1[i] == '[' && s1[i + 1] == ']') k++;
    if (s[i] == '(' && s[i + 1] == ')')
      if (s1[i] == '8' && s1[i + 1] == '<') k++;
    if (s[i] == '(' && s[i + 1] == ')')
      if (s1[i] == '[' && s1[i + 1] == ']') k--;
    if (s[i] == '[' && s[i + 1] == ']')
      if (s1[i] == '8' && s1[i + 1] == '<') k--;
    if (s[i] == '[' && s[i + 1] == ']')
      if (s1[i] == '(' && s1[i + 1] == ')') k++;
  }
  if (k > 0)
    cout << "TEAM 1 WINS" << endl;
  else if (k < 0)
    cout << "TEAM 2 WINS" << endl;
  else
    cout << "TIE" << endl;
}
