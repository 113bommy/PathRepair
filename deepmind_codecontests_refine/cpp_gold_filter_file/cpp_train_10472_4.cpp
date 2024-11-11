#include <bits/stdc++.h>
using namespace std;
int n, len;
char tmp[10], t[105];
string s;
map<string, int> f;
inline int work(int l, int r) {
  int w = 0;
  for (int i = r; i >= l; i--) {
    w += t[i] == '(';
    w -= t[i] == ')';
    if (!w && (t[i] == '+' || t[i] == '-')) {
      int lft = work(l, i - 1), rgt = work(i + 1, r);
      if (lft == 2 || rgt == 2) return 2;
      if (t[i] == '+')
        return 3;
      else {
        if (rgt == 3)
          return 2;
        else
          return 3;
      }
    }
  }
  w = 0;
  for (int i = r; i >= l; i--) {
    w += t[i] == '(';
    w -= t[i] == ')';
    if (!w && (t[i] == '*' || t[i] == '/')) {
      int lft = work(l, i - 1), rgt = work(i + 1, r);
      if (lft == 2 || rgt == 2) return 2;
      if (t[i] == '*') {
        if (lft == 3 || rgt == 3)
          return 2;
        else
          return 4;
      } else {
        if (lft == 3 || rgt == 3 || rgt == 4)
          return 2;
        else
          return 4;
      }
    }
  }
  if (t[l] == '(')
    if (work(l + 1, r - 1) == 2)
      return 2;
    else
      return 1;
  string x(t + l, t + r + 1);
  if (f[x])
    return f[x];
  else
    return 1;
}
inline int get() {
  gets(t);
  int m = 0;
  len = strlen(t);
  for (int i = 0; i < len; i++)
    if (t[i] != ' ') t[m++] = t[i];
  t[m] = '\0';
  return work(0, m - 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf(" #%s", tmp);
    cin >> s;
    f[s] = get();
  }
  if (get() != 2)
    puts("OK");
  else
    puts("Suspicious");
  return 0;
}
