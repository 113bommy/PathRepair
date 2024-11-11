#include <bits/stdc++.h>
using namespace std;
string space(string s) {
  string ret;
  for (int i = 0; i < s.length(); i++)
    if (s[i] != ' ') ret += s[i];
  return ret;
}
map<string, int> res;
int n;
int solve(string s) {
  if (res.count(s)) return res[s];
  int len = s.length();
  int t0, t1, t2;
  int stk = 0;
  if (s[0] == '(' && s[len - 1] == ')') {
    t0 = 1;
    for (int i = 0; i < len - 1; i++) {
      if (s[i] == '(') stk++;
      if (s[i] == ')') stk--;
      if (stk == 0) {
        t0 = 0;
        break;
      }
    }
    if (t0) {
      t1 = solve(s.substr(1, len - 2));
      if (t1 != -1)
        return 0;
      else
        return -1;
    }
  }
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] == '(') stk++;
    if (s[i] == ')') stk--;
    if (stk == 0 && (s[i] == '+' || s[i] == '-')) {
      t1 = solve(s.substr(0, i));
      t2 = solve(s.substr(i + 1));
      if (t1 == -1 || t2 == -1) return -1;
      if (s[i] == '-' && t2 == 1) return -1;
      return 1;
    }
  }
  stk = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] == '(') stk++;
    if (s[i] == ')') stk--;
    if (stk == 0 && (s[i] == '*' || s[i] == '/')) {
      t1 = solve(s.substr(0, i));
      t2 = solve(s.substr(i + 1));
      if (t1 == -1 || t2 == -1) return -1;
      if (t1 == 1) return -1;
      if (t2 == 1 && s[i] == '*') return -1;
      if ((t2 == 1 || t2 == 2) && s[i] == '/') return -1;
      return 2;
    }
  }
  return 0;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s1, s2;
    char t;
    int cnt = 0;
    while (cnt < 2 && cin >> t)
      if (t == 'e') cnt++;
    cin >> s1;
    getline(cin, s2);
    s2 = space(s2);
    res[s1] = solve(s2);
  }
  string s;
  getline(cin, s);
  s = space(s);
  if (solve(s) != -1)
    puts("OK");
  else
    puts("Suspicious");
}
int main() {
  solve();
  return 0;
}
