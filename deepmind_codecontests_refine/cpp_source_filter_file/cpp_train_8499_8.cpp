#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXLEN = 10;
const int MAXH = 3 * MAXLEN;
const int MAXW = 2 * 255 + 4;
char s[MAXLEN + 1];
int slen;
int nmin[MAXLEN];
char g[MAXH][MAXW + 1];
void run() {
  scanf("%s", s);
  slen = strlen(s);
  int at = 0;
  for (int i = (0); i < (slen); ++i) {
    int to = (int)s[i];
    nmin[i] = (at - to + 256) % 256;
    if (nmin[i] == 0) nmin[i] += 256;
    at = to;
  }
  int h = 3 * slen, w = 2 * 255 + 4;
  for (int x = (0); x < (h); ++x) {
    for (int y = (0); y < (w); ++y) g[x][y] = '.';
    g[x][w] = '\0';
  }
  for (int i = (0); i < (slen); ++i) {
    for (int j = (0); j < (nmin[i] - 1); ++j) g[3 * i + 0][2 * j + 1] = 'X';
    g[3 * i + 0][w - 2] = 'X';
    for (int j = (0); j < (2 * nmin[i] - 1); ++j) g[3 * i + 1][j] = 'X';
    g[3 * i + 1][w - 2] = 'X';
  }
  for (int x = (0); x < (h); ++x) printf("%s\n", g[x]);
}
int main() {
  run();
  return 0;
}
