#include <bits/stdc++.h>
using namespace std;
bool is_upercase(char c) { return c >= 'A' && c <= 'Z'; }
string solve(string s) {
  int res = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '4' || s[i] == '7') res++;
  return res == '4' || res == '7' ? "YES" : "NO";
}
int main() {
  string s;
  int n, k;
  cin >> s;
  cout << solve(s) << endl;
}
