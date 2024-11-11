#include <bits/stdc++.h>
using namespace std;
int sp;
string s;
string nextToken() {
  if (sp == s.size()) return "";
  while (sp < s.size() && s[sp] == ' ') sp++;
  if (isalnum(s[sp])) {
    int si = sp;
    while (sp < s.size() && isalnum(s[sp])) sp++;
    return s.substr(si, sp - si);
  } else
    return string(1, s[sp++]);
}
map<string, char> m;
string token;
char expr();
char addend();
char multiplier();
char expr() {
  char r = addend();
  while (token == "+" || token == "-") {
    string t = token;
    char k = addend();
    if (k == 'x' || (t == "-" && k == '+')) r = 'x';
    if (r != 'x') r = '+';
  }
  return r;
}
char addend() {
  char r = multiplier();
  while (token == "*" || token == "/") {
    string t = token;
    char k = multiplier();
    if (r == '+' || k == '+' || k == 'x' || (t == "/" && k == '*')) r = 'x';
    if (r != 'x') r = '*';
  }
  return r;
}
char multiplier() {
  token = nextToken();
  if (token == "(") {
    char r = expr();
    token = nextToken();
    if (r == 'x')
      return 'x';
    else
      return 'o';
  } else {
    string name = token;
    token = nextToken();
    if (m.find(name) != m.end()) {
      return m[name];
    } else
      return 'o';
  }
}
int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    sp = 0;
    nextToken();
    nextToken();
    string name = nextToken();
    m[name] = expr();
  }
  getline(cin, s);
  sp = 0;
  if (expr() == 'x')
    cout << "Suspicious" << endl;
  else
    cout << "OK" << endl;
  return 0;
}
