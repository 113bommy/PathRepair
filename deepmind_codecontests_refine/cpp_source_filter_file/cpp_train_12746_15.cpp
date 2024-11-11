#include <bits/stdc++.h>
using namespace std;
int main() {
  char aa[] = "AHIMOTUVWX";
  string s;
  int check(char aa[], char c);
  int palin(string s);
  int f = 1, a;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    a = check(aa, s[i]);
    if (a == 0) {
      f = 0;
      break;
    }
  }
  if (f == 1) {
    a = palin(s);
    if (a == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else
    cout << "NO\n";
  return 0;
}
int check(char aa[], char c) {
  int i;
  for (i = 0; i < 10; i++) {
    if (aa[i] == c) break;
  }
  if (i < 10) return 1;
  return 0;
}
int palin(string s) {
  int f = 1, l, i, j;
  l = s.size() / 2;
  j = s.size() - 1;
  for (i = 0; i < l; i++, j--) {
    if (s[i] != s[j]) {
      f = 0;
      break;
    }
  }
  if (f == 1) return 1;
  return 0;
}
