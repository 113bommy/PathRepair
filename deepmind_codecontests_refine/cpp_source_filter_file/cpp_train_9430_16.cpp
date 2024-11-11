#include <bits/stdc++.h>
using namespace std;
bool tr(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
bool tr1(char c1) {
  return (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u');
}
bool tr2(char c2) {
  return (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u');
}
int main() {
  string s, s1, s2;
  getline(cin, s);
  getline(cin, s1);
  getline(cin, s2);
  int a = 0, d = 0, e = 0;
  for (auto u : s) {
    char c = tolower(u);
    if (tr(c) == 1) a++;
  }
  for (auto u : s1) {
    char c1 = tolower(u);
    if (tr1(c1) == 1) d++;
  }
  for (auto u : s2) {
    char c2 = tolower(u);
    if (tr2(c2) == 1) e++;
  }
  if (a == 5 && d == 7 && e == 5)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
