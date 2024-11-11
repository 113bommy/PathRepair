#include <bits/stdc++.h>
using namespace std;
int n, m;
string ans[] = {"abc", "acb"};
string a[2][3] = {{"ab", "bc", "ca"}, {"ac", "ba", "cb"}};
string s[2];
void prin1(string s, int n) {
  for (int i = 0; i < n; i++) cout << s;
  exit(0);
}
void prin(char x, int n) {
  for (int i = 0; i < n; i++) cout << x;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> s[0] >> s[1];
  cout << "YES"
       << "\n";
  for (int i = 0; i < 2; i++) {
    int c = 0;
    for (int j = 0; j < 3; j++) {
      if (s[0] == a[i][j] || s[1] == a[i][j]) c++;
    }
    if (c == 0) prin1(ans[i], n);
  }
  if (s[0][0] == s[1][0]) {
    prin(s[0][1], n), prin(s[1][1], n), prin(s[1][0], n);
    exit(0);
  }
  if (s[0][1] == s[1][1]) {
    prin(s[1][1], n), prin(s[0][0], n), prin(s[1][0], n);
    exit(0);
  }
  if (s[0][1] == s[1][0]) {
    if (s[0] == "ab" || s[0] == "ba")
      prin(s[0][0], n), prin('c', n), prin(s[0][1], n);
    else if (s[0] == "bc" || s[0] == "bc")
      prin(s[0][0], n), prin('a', n), prin(s[0][1], n);
    else if (s[0] == "ca" || s[0] == "ca")
      prin(s[0][0], n), prin('b', n), prin(s[0][1], n);
  }
  return 0;
}
