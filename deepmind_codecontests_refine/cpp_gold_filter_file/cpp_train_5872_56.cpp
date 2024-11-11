#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
char s[1000][1000];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 3 && m == 2) {
    puts(">vv");
    puts("^<.");
    puts(">.<");
    puts("1 3");
  } else if (n == 5) {
    puts(">.>.v");
    puts("v.<..");
    puts(">...v");
    puts(">.^..");
    puts("^.<.<");
    puts("1 1");
  } else {
    for (int i = 0; i < (n); ++i)
      for (int j = 0; j < (n); ++j) s[i][j] = '.';
    for (int i = 0; i < (n / 3 + 1); ++i) s[0][i] = '>';
    for (int i = n / 3 + 2; i < n - 1; i += 2) s[0][i] = '>';
    s[0][n - 1] = 'v';
    for (int i = (1); i < (n - 1); ++i) {
      if (i & 1) {
        for (int j = 0; j < (n / 3); ++j) s[i][n - 1 - j] = '<';
        for (int j = n - 1 - n / 3 - 1; j > 1; j -= 2) s[i][j] = '<';
        s[i][1] = 'v';
      } else {
        for (int j = 0; j < (n / 3); ++j) s[i][1 + j] = '>';
        for (int j = 1 + n / 3 + 1; j < n - 1; j += 2) s[i][j] = '>';
        s[i][n - 1] = 'v';
      }
    }
    for (int j = 0; j < (n / 3); ++j) s[n - 1][n - 1 - j] = '<';
    for (int j = n - 1 - n / 3 - 1; j > 0; j -= 2) s[n - 1][j] = '<';
    s[n - 1][0] = '^';
    for (int j = 0; j < (n / 3); ++j) s[n - 2 - j][0] = '^';
    for (int j = n - 3 - n / 3; j > 0; j -= 2) s[j][0] = '^';
    for (int i = 0; i < (n); ++i) puts(s[i]);
    puts("1 1");
  }
  return 0;
}
