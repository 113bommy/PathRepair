#include <bits/stdc++.h>
using namespace std;
char s[3];
char p[105][3];
int main() {
  int i, j, k, n;
  gets(s);
  cin >> n;
  scanf("\n");
  for (i = 0; i < n; i++) {
    gets(p[i]);
  }
  for (i = 0; i < n; i++) {
    if (strcmp(p[i], s) == 0) {
      cout << "YES";
      return 0;
    }
  }
  for (i = 0; i < n; i++) {
    if (p[i][0] == s[1]) {
      j = 1;
    }
    if (p[i][1] == s[0]) {
      k = 1;
    }
  }
  if (j == 1 && k == 1) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
