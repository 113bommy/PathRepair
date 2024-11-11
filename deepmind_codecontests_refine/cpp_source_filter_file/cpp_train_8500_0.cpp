#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, SS = 150 * 150 + 150;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int N, M, Len, id;
bitset<SS> now, B, can;
char s[151], str[MAXN];
int main() {
  N = read();
  M = read();
  Len = read();
  for (int i = 1; i <= N; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= M; j++) {
      if (s[j] == '#')
        B[i * M + j] = 1;
      else
        can[i * M + j] = now[i * M + j] = 1;
      if (s[j] == 'E') id = i * M + j;
    }
  }
  scanf("%s", str + 1);
  if (now.count() == 1 && now[id] == 1) return puts("0"), 0;
  for (int i = 1; i <= Len; i++) {
    if (str[i] == 'U') {
      now = ((now >> M) & can) | (now & (B << M));
    } else if (str[i] == 'D') {
      now = ((now << M) & can) | (now & (B >> M));
    } else if (str[i] == 'L') {
      now = ((now >> 1) & can) | (now & (B << 1));
    } else if (str[i] == 'R') {
      now = ((now >> M) & can) | (now & (B << M));
    }
    if (now.count() == 1 && now[id] == 1) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
