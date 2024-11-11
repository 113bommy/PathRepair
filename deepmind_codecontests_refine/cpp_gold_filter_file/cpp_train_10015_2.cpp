#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 10;
char s[N][N];
int r, c, cnt, k, e;
char get_char(int x) {
  if (x <= 26) return 'A' + x - 1;
  if (x <= 52) return 'a' + x - 1 - 26;
  return '0' + x - 53;
}
void get_next_index(int &i, int &j) {
  if (i & 1) {
    if (j == c)
      i++;
    else
      j++;
  } else {
    if (j == 1)
      i++;
    else
      j--;
  }
}
void solve() {
  int i = 1, j = 1, t = 1, c = 0;
  while (1) {
    if (i == r + 1) break;
    int goal = cnt / k + (cnt % k >= t);
    c += (s[i][j] == 'R');
    if (c > goal) c = 1, t++;
    s[i][j] = get_char(t);
    get_next_index(i, j);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &r, &c, &k);
    cnt = 0;
    for (int i = 1; i <= r; i++) {
      scanf("%s", s[i] + 1);
      for (int j = 1; j <= c; j++) cnt += (s[i][j] == 'R');
    }
    solve();
    for (int i = 1; i <= r; i++) {
      printf("%s\n", s[i] + 1);
    }
  }
  return 0;
}
