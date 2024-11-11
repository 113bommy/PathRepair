#include <bits/stdc++.h>
using namespace std;
const int N = 10101;
char s[N], t[N * 100];
int ne[N][26];
int main() {
  scanf("%s", s);
  int lens = strlen(s);
  for (int i = lens; i >= 0; --i) {
    for (int d = 0; d < (26); ++d) ne[i][d] = i == lens ? lens : ne[i + 1][d];
    if (i != lens) ne[i][s[i] - 'a'] = i;
  }
  scanf("%s", t);
  int len = strlen(t);
  int cnt = 0;
  for (int i = 0, j = 0; i < len; i = j) {
    ++cnt;
    for (int c = 0; j < len && ne[c][t[j] - 'a'] != lens; j++) {
      c = ne[c][t[j] - 'a'];
    }
    if (i == j) {
      puts("-1");
      return 0;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
