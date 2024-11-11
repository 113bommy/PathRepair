#include <bits/stdc++.h>
using namespace std;
const int N = 101010;
const int INF = 1 << 30;
inline char get(void) {
  static char buf[100000], *S = buf, *T = buf;
  if (S == T) {
    T = (S = buf) + fread(buf, 1, 100000, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
template <typename T>
inline void read(T &x) {
  static char c;
  x = 0;
  int sgn = 0;
  for (c = get(); c < '0' || c > '9'; c = get())
    if (c == '-') sgn = 1;
  for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
  if (sgn) x = -x;
}
char ch[N][10];
char ans[N][10];
char sub[10];
int n, c, num;
int l[N];
map<int, int> mp;
inline int Dec(char *ch, int n) {
  int x = 0;
  for (int i = 0; i < n; i++) x = x * 10 + ch[i] - '0';
  return x;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", ch[i]);
  for (int i = 1; i <= 9; i++) {
    mp.clear();
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k + i <= 9; k++) {
        c = 0;
        for (int x = k; x < k + i; x++) sub[c++] = ch[j][x];
        num = Dec(sub, c);
        if (!mp.count(num))
          mp[num] = j;
        else if (mp[num] != j)
          mp[num] = INF;
      }
    }
    for (int j = 1; j <= n; j++) {
      if (l[j]) continue;
      for (int k = 0; k + i <= 9; k++) {
        c = 0;
        for (int x = k; x < k + i; x++) sub[c++] = ch[j][x];
        num = Dec(sub, c);
        if (mp[num] == j && !l[j]) {
          l[j] = c;
          for (int x = 0; x < c; x++) ans[j][x] = sub[x];
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < l[i]; j++) putchar(ans[i][j]);
    putchar('\n');
  }
  return 0;
}
