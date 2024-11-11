#include <bits/stdc++.h>
using namespace std;
const int X = 100005;
char s[X];
char out[X];
vector<int> a[27];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  int x;
  for (int i = 0; i < len; i++) {
    x = s[i] - 'a';
    a[x].push_back(i);
  }
  int temp = 0, cnt = 0;
  for (int i = 25; i >= 0; i--) {
    len = a[i].size();
    for (int j = 0; j < len; j++) {
      x = a[i][j];
      if (x >= temp) {
        temp = x;
        out[cnt++] = s[x];
      }
    }
  }
  out[cnt] = '\0';
  printf("%s\n", out);
  return 0;
}
