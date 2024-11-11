#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
int main() {
  char s[1010] = {0}, t[SIZE] = {0};
  cin >> s >> t;
  int end = -1, start = -1, p = 0;
  int slen = strlen(s);
  int tlen = strlen(t);
  for (int i = 0; i < (tlen); ++i) {
    if (t[i] == s[p]) p++;
    if (p == slen) {
      end = i;
      break;
    }
  }
  p = slen - 1;
  for (int i = tlen - 1; i > -1; i--) {
    if (t[i] == s[p]) p--;
    if (p == -1) {
      start = i;
      break;
    }
  }
  if (start != -1 && end != -1) {
    cout << (max(start - end, 0));
  } else {
    cout << 0;
  }
}
