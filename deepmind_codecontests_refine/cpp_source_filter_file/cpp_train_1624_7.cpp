#include <bits/stdc++.h>
using namespace std;
char s[100005];
char match[15][15];
int n, len[15], slen;
int fin[100005];
int m[100005];
int main() {
  scanf("%s", s);
  scanf("%d", &n);
  for (int i = 0, _e(n); i < _e; i++) scanf("%s", match[i]);
  for (int i = 0, _e(n); i < _e; i++) len[i] = strlen(match[i]);
  slen = strlen(s);
  for (int i = 0, _e(slen); i < _e; i++) {
    for (int j = 0, _e(n); j < _e; j++) {
      if (i + len[j] <= slen) {
        bool ok = 1;
        for (int k = 0, _e(len[j]); k < _e; k++)
          if (match[j][k] != s[i + k]) ok = 0;
        if (ok) {
          if (!fin[i])
            fin[i] = len[j];
          else
            fin[i] = min(fin[i], len[j]);
        }
      }
    }
  }
  int a = 0, b = 0, last;
  last = slen;
  for (int i(slen - 1), _e(0); i >= _e; i--) {
    if (fin[i]) last = min(last, i + fin[i]);
    if (last - i > a) a = last - i - 1, b = i;
  }
  cout << a << " " << b << endl;
  return 0;
}
