#include <bits/stdc++.h>
using namespace std;
const int LEN = 1e5 + 5;
char s[LEN];
char a[LEN];
char b[LEN];
bool is_sp(char c) { return c == ';' or c == ','; }
void solve() {
  int n = strlen(s);
  s[n] = ';';
  int i = -1, j = 0, p = 0, q = 0;
  bool has = false;
  for (; j <= n; j++) {
    if (is_sp(s[j])) {
      if (j > i + 1) {
        if (has) {
          memcpy(b + q, s + i + 1, j - i - 1);
          q += j - i - 1;
          b[q++] = ',';
        } else {
          if (j - i - 1 > 1 and s[i + 1] == '0') {
            memcpy(b + q, s + i + 1, j - i - 1);
            q += j - i - 1;
            b[q++] = ',';
          } else {
            memcpy(a + p, s + i + 1, j - i - 1);
            p += j - i - 1;
            a[p++] = ',';
          }
        }
      } else
        b[q++] = ',';
      i = j;
      has = false;
    } else {
      if (!has and ((s[j] > 'A' and s[j] <= 'z') || s[j] == '.')) has = true;
    }
  }
  bool f2 = q;
  if (p) {
    a[--p] = 0;
  }
  if (f2) {
    b[--q] = 0;
  }
  if (p)
    printf("\"%s\"\n", a);
  else
    cout << "-" << endl;
  if (f2)
    printf("\"%s\"\n", b);
  else
    cout << "-" << endl;
}
int main() {
  cin >> s;
  solve();
  return 0;
}
