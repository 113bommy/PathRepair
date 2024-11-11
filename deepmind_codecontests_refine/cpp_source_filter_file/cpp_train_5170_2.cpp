#include <bits/stdc++.h>
using namespace std;
int n, i, k, j;
bool flag[200];
char t[200], s[200][200], l, L;
bool cmp(int a, int b, char s1[], char s2[], int n) {
  for (int i = 0; i < n; i++) {
    char c1 = s1[a + i];
    if (c1 >= 'A' && c1 <= 'Z') c1 = c1 - 'A' + 'a';
    char c2 = s2[b + i];
    if (c2 >= 'A' && c2 <= 'Z') c2 = c2 - 'A' + 'a';
    if (c1 != c2) return 0;
  }
  return 1;
}
int main() {
  cin >> n;
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  scanf("%s", t);
  cin >> l;
  char L = 'A' + (l - 'a');
  for (i = 0; i < strlen(t); i++) {
    bool ok = 0;
    for (k = 0; !ok && k < n; k++) {
      int len = strlen(s[k]);
      for (j = 0; !ok && j <= i; j++)
        if (j + len - 1 >= i) ok |= cmp(j, 0, t, s[k], len);
    }
    flag[i] = ok;
  }
  for (i = 0; i < strlen(t); i++) {
    if (flag[i]) {
      if (t[i] >= 'A' && t[i] <= 'Z') {
        if (t[i] == L) {
          if (t[i] == 'A')
            t[i] = 'B';
          else
            t[i] = 'A';
        } else
          t[i] = L;
      } else {
        if (t[i] == l) {
          if (t[i] == 'a')
            t[i] = 'b';
          else
            t[i] = 'b';
        } else
          t[i] = l;
      }
    }
  }
  cout << t;
  return 0;
}
