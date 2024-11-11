#include <bits/stdc++.h>
using namespace std;
string s;
int countp = 0;
void par(int st, int e) {
  int x = st;
  while (s[st] != '_' && st <= e) {
    st++;
  }
  if (st != x) countp++;
  for (int i = st + 1; i <= e; i++) {
    if (i == e && s[i] != '_') {
      countp++;
    }
    if (s[i] == '_') {
      if (i - st > 1) countp++;
      st = i;
    }
  }
}
int main() {
  string S;
  int i;
  cin >> i;
  cin >> S;
  s = '_' + S;
  i = 0;
  int j;
  int c = 0, max = INT_MIN;
  for (; i < s.length();) {
    if (s[i] == '_' || s[i] == ')') {
      j = i + 1;
      while (s[j] != '(' && s[j] != '_' && j < s.length()) j++;
      c = j - i - 1;
      if (max < c) max = c;
      i = j;
    }
    if (s[i] == '(') {
      j = i + 1;
      while (s[j] != ')' && j < s.length()) j++;
      par(i + 1, j - 1);
      i = j;
    }
  }
  cout << max << " " << countp;
  return 0;
}
