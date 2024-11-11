#include <bits/stdc++.h>
using namespace std;
bool check(string &s, int beg, int end) {
  if (beg > end) return false;
  for (int i = beg; i <= end; ++i)
    if (s[i] > '9' || s[i] < '0') return false;
  if (s[beg] == '0' && beg != end) return false;
  return true;
}
void addword(string &dest, string &source, int beg, int end) {
  for (int i = beg; i <= end; ++i) dest.push_back(source[i]);
  dest.push_back(',');
}
void print(string &s) {
  if (((int)s.length()) == 0)
    printf("-1\n");
  else {
    printf("\"");
    s.pop_back();
    cout << s;
    printf("\"\n");
  }
}
void solve() {
  string s;
  cin >> s;
  for (int i = 0; i < ((int)s.length()); ++i)
    if (s[i] == ',') s[i] = ';';
  s = s + ';';
  string s1, s2;
  for (int i = 0; i < ((int)s.length()); ++i) {
    int pointer = i;
    while (pointer < ((int)s.length()) && s[pointer] != ';') pointer++;
    if (check(s, i, pointer - 1))
      addword(s1, s, i, pointer - 1);
    else
      addword(s2, s, i, pointer - 1);
    i = pointer;
  }
  print(s1), print(s2);
}
int main() {
  solve();
  return 0;
}
