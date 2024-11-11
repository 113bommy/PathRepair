#include <bits/stdc++.h>
using namespace std;
int N;
char s[100005];
inline int read_int() {
  register int ret = 0, f = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = (ret << 1) + (ret << 3) + int(c - 48);
    c = getchar();
  }
  return ret * f;
}
inline void init() {
  scanf("%s", s + 1);
  N = strlen(s + 1);
  int cnt = 1;
  for (register int i = 1; i <= N; i++) {
    if (cnt == 27) break;
    if (s[i] <= cnt + 'a' - 1) s[i] = cnt + 'a' - 1, cnt++;
  }
  if (cnt == 27) {
    for (register int i = 1; i <= N; i++) printf("%c", s[i]);
    printf("\n");
  } else
    printf("-1\n");
}
int main() {
  init();
  return 0;
}
