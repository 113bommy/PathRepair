#include <bits/stdc++.h>
using namespace std;
int n, m, l, ll;
char s[1000], name[1000], ss[1000];
bool check() {
  for (int i = 0; i < ll; i++)
    if (ss[i] == '0') {
      bool tmp = 1;
      for (int j = 0; j < l; j++)
        if (s[i + j] != s[j]) {
          tmp = 0;
          break;
        }
      if (tmp) return false;
    } else {
      bool tmp = 1;
      for (int j = 0; j < l; j++)
        if (s[i + j] != s[j]) {
          tmp = 0;
          break;
        }
      if (!tmp) return false;
    }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  srand(time(NULL));
  gets(s);
  gets(name);
  gets(s);
  l = strlen(name);
  ll = strlen(s);
  for (int i = 0; i < l; i++) s[i + ll] = '0';
  s[l + ll - 1] = 0;
  for (int i = 0; i < 1000; i++) ss[i] = s[i];
  ll = strlen(s);
  for (int i = ll - 1; i >= 0; i--)
    if (s[i] == '1')
      for (int j = 0; j < l; j++) s[i + j] = name[j];
  bool pass = check();
  for (int i = 0; i < ll; i++)
    if (s[i] == '0') {
      bool tmp = 0;
      for (int j = 0; j < m; j++) {
        s[i] = 'a' + j;
        if (check()) {
          tmp = 1;
          break;
        }
      }
      if (!tmp) {
        pass = 0;
        break;
      }
    }
  if (pass)
    printf("%s\n", s);
  else
    printf("No solution\n");
  return 0;
}
