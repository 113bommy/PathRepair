#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int nxt[N][26];
long long cc[26];
char s[N];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = (n + 1) - 1; i >= (1); --i) {
    for (int j = (0); j < (26); ++j) {
      if (j == s[i] - 'a')
        nxt[i][j] = i;
      else
        nxt[i][j] = nxt[i + 1][j];
    }
  }
  int nn = 0;
  for (int i = (1); i < (n + 1); ++i) {
    sort(nxt[i], nxt[i] + 26);
    int last = i, now = 0;
    for (int j = (0); j < (26); ++j) {
      if (nxt[i][j] == 0)
        continue;
      else
        cc[now++] += nxt[i][j] - last, last = nxt[i][j];
    }
    cc[now++] += n + 1 - last;
    nn = max(nn, now - 1);
  }
  printf("%d\n", nn);
  for (int i = (1); i < (nn + 1); ++i) printf("%d\n", cc[i]);
  return 0;
}
