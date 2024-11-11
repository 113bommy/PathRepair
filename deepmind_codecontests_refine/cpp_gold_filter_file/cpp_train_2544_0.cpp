#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1111][1111], r[1111][1111];
char b[11];
void result() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%c", r[i][j]);
    puts("");
  }
}
bool process1() {
  int cd1 = 0, cd2 = 1;
  for (int i = 1; i <= n; ++i) {
    cd2 = 1;
    for (int j = 1; j <= m; ++j) r[i][j] = b[cd1 + cd2], cd2 = 3 - cd2;
    bool check = 0;
    for (int j = 1; j <= m; ++j)
      if (s[i][j] != '0' && s[i][j] != r[i][j]) {
        check = 1;
        break;
      }
    if (!check) {
      cd1 = 2 - cd1;
      continue;
    }
    cd2 = 2;
    for (int j = 1; j <= m; ++j) r[i][j] = b[cd1 + cd2], cd2 = 3 - cd2;
    check = 0;
    for (int j = 1; j <= m; ++j)
      if (s[i][j] != '0' && s[i][j] != r[i][j]) {
        check = 1;
        break;
      }
    if (check) return 0;
    cd1 = 2 - cd1;
  }
  return 1;
}
bool process2() {
  int cd1 = 0, cd2 = 1;
  for (int j = 1; j <= m; ++j) {
    cd2 = 1;
    for (int i = 1; i <= n; ++i) r[i][j] = b[cd1 + cd2], cd2 = 3 - cd2;
    bool check = 0;
    for (int i = 1; i <= n; ++i)
      if (s[i][j] != '0' && s[i][j] != r[i][j]) {
        check = 1;
        break;
      }
    if (!check) {
      cd1 = 2 - cd1;
      continue;
    }
    cd2 = 2;
    for (int i = 1; i <= n; ++i) r[i][j] = b[cd1 + cd2], cd2 = 3 - cd2;
    check = 0;
    for (int i = 1; i <= n; ++i)
      if (s[i][j] != '0' && s[i][j] != r[i][j]) {
        check = 1;
        break;
      }
    if (check) return 0;
    cd1 = 2 - cd1;
  }
  return 1;
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s\n", s[i] + 1);
  }
  for (int i = 1; i < 5; ++i) b[i] = '0' + i;
  do {
    if (process1()) {
      result();
      return 0;
    }
    if (process2()) {
      result();
      return 0;
    }
  } while (next_permutation(b + 1, b + 5));
  cout << '0' << '\n';
  return 0;
}
