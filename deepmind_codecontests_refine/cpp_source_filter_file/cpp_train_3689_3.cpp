#include <bits/stdc++.h>
using namespace std;
int sz;
int len[100];
int val[100];
bool b[100][100];
int pos(char* s, char c) {
  for (int i = 0; s[i]; ++i) {
    if (s[i] == c) {
      return i;
    }
  }
  return -1000010101;
}
int getLen(char* s, int i) {
  int j = i;
  while (s[j] == '_') ++j;
  return j - i;
}
int main() {
  char s[10000];
  gets(s);
  int l = pos(s, '(');
  int r = pos(s, ')');
  for (int i = l; i < r; ++i) {
    if (s[i] != '_') continue;
    len[sz++] = getLen(s, i);
    i = i + len[sz - 1];
  }
  l = pos(s, ':') + 2;
  r = pos(s, '.');
  for (int i = l; i < r; ++i) {
    if (s[i] != '_') continue;
    int l1 = getLen(s, i);
    int l2 = getLen(s, i + l1 + 1);
    if (s[i + l1] == '>') swap(l1, l2);
    b[l1][l2] = true;
    i = i + l1 + 1 + l2;
  }
  for (bool did = true; did;) {
    did = false;
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        int l1 = len[i];
        int l2 = len[j];
        if (val[l1] >= val[l2] && b[l1][l2]) {
          val[l2] = val[l1] + 1;
          did = true;
          if (val[l2] >= 10) {
            puts("false");
            return 0;
          }
        }
      }
    }
  }
  for (int i = 0; i < sz; ++i) {
    putchar('0' + val[len[i]]);
  }
  return 0;
}
