#include <bits/stdc++.h>
using namespace std;
int b[26];
int main() {
  queue<string> q;
  string r;
  int n, i, j, f;
  char a[40][25];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", a[i]);
    for (j = 0; a[i][j] != '\0'; j++) {
      b[a[i][j] - 'a'] = 1;
    }
  }
  for (i = 0; i < 26; i++) {
    if (b[i] == 0) break;
    stringstream ss;
    char h = 'a' + i;
    ss << h;
    ss >> r;
    q.push(r);
  }
  if (i != 26)
    printf("%c", i + 'a');
  else {
    while (!q.empty()) {
      r = q.front();
      q.pop();
      f = 0;
      string l;
      for (i = 0; i < 26; i++) {
        string s;
        char h = 'a' + i;
        stringstream ss;
        ss << h;
        ss >> s;
        l = r + s;
        f = 0;
        q.push(l);
        for (i = 0; i < n; i++)
          if (strstr(a[i], l.c_str()) != NULL) {
            f = 1;
            break;
          }
        if (f == 0) {
          cout << l;
          break;
        }
      }
      if (f == 0) break;
    }
  }
  return 0;
}
