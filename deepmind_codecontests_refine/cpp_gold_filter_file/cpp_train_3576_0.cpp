#include <bits/stdc++.h>
using namespace std;
string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline int decode(char c) {
  if (c >= 'a' && c <= 'z') return c - 'a';
  return c - 'A' + 26;
}
inline char encode(int a) {
  if (a >= 0 && a <= 25) return 'a' + a;
  return 'A' + a - 26;
}
inline int getnum(string str) {
  int base = 0;
  switch (str[1]) {
    case 'S':
      base = 0;
      break;
    case 'D':
      base = 1;
      break;
    case 'H':
      base = 2;
      break;
    default:
      base = 3;
      break;
  }
  string s = "23456789TJQKA";
  int ans = (base * 13);
  for (int i = 0; i < s.length(); i++) {
    if (str[0] == s[i]) return ans + i;
  }
}
inline bool eq(int a, int b) {
  if (a % 13 == b % 13 || a / 13 == b / 13) return true;
  return false;
}
char cards[55][5];
string top;
map<string, bool> app;
bool dfs(int n) {
  if (n == 0) return true;
  bool ans = false;
  if (n - 3 >= 0 && eq(decode(top[n]), decode(top[n - 3]))) {
    char tmp = top[n - 3];
    top[n - 3] = top[n];
    string pretop = top.substr(0, n);
    if (app.find(pretop) == app.end()) {
      app[pretop] = true;
      ans = dfs(n - 1);
    }
    top[n - 3] = tmp;
    if (ans) return true;
  }
  if (n - 1 >= 0 && eq(decode(top[n]), decode(top[n - 1]))) {
    char tmp = top[n - 1];
    top[n - 1] = top[n];
    string pretop = top.substr(0, n);
    if (app.find(top) == app.end()) {
      app[pretop] = true;
      ans = dfs(n - 1);
    }
    top[n - 1] = tmp;
    if (ans) return true;
  }
  return false;
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    top = "";
    for (int i = 0; i < n; i++) {
      scanf("%s", cards[i]);
      top += encode(getnum(cards[i]));
    }
    app.clear();
    printf("%s\n", dfs(n - 1) ? "YES" : "NO");
  }
  return 0;
}
