#include <bits/stdc++.h>
using namespace std;
int cnt_s[33];
int cnt_t[33];
string s, t;
int ls, lt, fl;
int need_tree() {
  int i, j, k, l;
  for (i = 1; i <= 26; i++) {
    if (cnt_s[i] < cnt_t[i]) return 1;
  }
  return 0;
}
int isAutomation() {
  int i, j, k, l;
  i = 0;
  j = 0;
  while (i < ls) {
    if (j < lt && s[i] == t[j]) j++;
    i++;
  }
  if (j == lt) return 1;
  return 0;
}
int main() {
  cin >> s >> t;
  ls = (int)s.size();
  lt = (int)t.size();
  int x, i;
  for (i = 0; i < ls; i++) {
    x = s[i] - 'a' + 1;
    cnt_s[x]++;
  }
  for (i = 0; i < lt; i++) {
    x = t[i] - 'a' + 1;
    cnt_t[x]++;
  }
  if (need_tree() == 1)
    cout << "need tree\n";
  else if (isAutomation() == 1)
    cout << "automaton\n";
  else if (ls == lt)
    cout << "array\n";
  else
    cout << "both\n";
  return 0;
}
