#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  if ((s[0] == '<' && t[0] == '^') || (s[0] == '>' && t.back() == '^') ||
      (s.back() == '<' && t[0] == 'v') || (s.back() == '>' && t.back() == 'v'))
    cout << "no";
  else
    cout << "yes";
}
