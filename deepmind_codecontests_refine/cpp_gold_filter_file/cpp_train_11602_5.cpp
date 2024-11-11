#include <bits/stdc++.h>
using namespace std;
using namespace std;
int n, r;
char s[100111];
char X[100111];
int main() {
  cin >> n;
  memset(X, 'X', sizeof(X));
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    X[len] = '\0';
    for (int j = 0; j < len; j++)
      if (s[j] != '?') {
        if (X[j] == 'X' or X[j] == s[j])
          X[j] = s[j];
        else
          X[j] = '?';
      }
  }
  int len = strlen(X);
  for (int i = 0; i < len; i++)
    if (X[i] == 'X') X[i] = 'x';
  printf("%s\n", X);
}
