#include <bits/stdc++.h>
using namespace std;
int n, sta[110], len;
char Name[110][110], o[110], s[110][110];
int Same(int k1, int k2, int l, int r) {
  if (strlen(Name[k1]) != (r - l + 1)) return 0;
  for (int i = l, j = 0; i <= r; i++, j++)
    if (Name[k1][j] != s[k2][i]) return 0;
  return 1;
}
int Get(int k, int l, int r) {
  int w = 0;
  for (int i = r; i >= l; i--) {
    w += s[k][i] == '(';
    w -= s[k][i] == ')';
    if (w == 0 && (s[k][i] == '+' || s[k][i] == '-')) {
      int t1 = Get(k, l, i - 1);
      int t2 = Get(k, i + 1, r);
      if (t1 == 0 || t2 == 0) return 0;
      if (s[k][i] == '-') {
        if (t2 == 1) return 0;
        return 1;
      } else
        return 1;
    }
  }
  for (int i = r; i >= l; i--) {
    w += s[k][i] == '(';
    w -= s[k][i] == ')';
    if (w == 0 && (s[k][i] == '*' || s[k][i] == '/')) {
      int t1 = Get(k, l, i - 1);
      int t2 = Get(k, i + 1, r);
      if (t1 == 0 || t2 == 0) return 0;
      if (t1 == 1 || t2 == 1) return 0;
      if (t2 == 2 && s[k][i] == '/') return 0;
      return 2;
    }
  }
  if (s[k][l] == '(') {
    int tt = Get(k, l + 1, r - 1);
    if (tt == 0) return 0;
    return 3;
  } else {
    for (int i = 1; i < k; i++)
      if (Same(i, k, l, r)) return sta[i];
    return 3;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n + 1; i++) {
    if (i <= n) {
      scanf(" #%s", o);
      cin >> Name[i];
    }
    gets(s[i]);
    len = strlen(s[i]);
    for (int j = 0; j < len; j++)
      if (s[i][j] == ' ') {
        for (int k = j; k < len; k++) s[i][k] = s[i][k + 1];
        len--;
        j--;
      }
    sta[i] = Get(i, 0, len - 1);
  }
  if (sta[n + 1] == 0)
    printf("Suspicious\n");
  else
    printf("OK\n");
  return 0;
}
