#include <bits/stdc++.h>
using namespace std;
string ans[100000];
string rotate90(string s);
string rotate(string s);
int main() {
  int n, r;
  cin >> n >> r;
  ans[1] = "urd";
  for (int i = 2; i <= n; i++)
    ans[i] = rotate90(ans[i - 1]) + "u" + ans[i - 1] + "r" + ans[i - 1] + "d" +
             rotate(ans[i - 1]);
  int x = 0;
  int y = 0;
  for (int i = 0; i < r; i++)
    if (ans[n][i] == 'u')
      y = y + 1;
    else if (ans[n][i] == 'd')
      y = y - 1;
    else if (ans[n][i] == 'r')
      x = x + 1;
    else
      x = x - 1;
  cout << x << ' ' << y << endl;
  return 0;
}
string rotate90(string s) {
  string s1 = "";
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'u')
      s1 += "r";
    else if (s[i] == 'r')
      s1 += "u";
    else if (s[i] == 'd')
      s1 += "l";
    else
      s1 += "d";
  return s1;
}
string rotate(string s) {
  string s1 = "";
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'u')
      s1 += "r";
    else if (s[i] == 'r')
      s1 += "d";
    else if (s[i] == 'd')
      s1 += "l";
    else
      s1 += "u";
  return s1;
}
