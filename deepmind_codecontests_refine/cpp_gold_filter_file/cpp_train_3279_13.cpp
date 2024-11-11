#include <bits/stdc++.h>
using namespace std;
const int int_inf = 0x3f3f3f3f;
const double double_inf = 1e30;
inline int readint() {
  bool neg = 0;
  char ch, t[11];
  int k = 0;
  while ((ch = getchar()) == ' ' || ch == '\n')
    ;
  neg = ch == '-';
  ch == '-' ? neg = 1 : t[k++] = ch;
  while ((ch = getchar()) >= '0' && ch <= '9') t[k++] = ch;
  int x = 0, y = 1;
  while (k) x += (t[--k] - '0') * y, y *= 10;
  return neg ? -x : x;
}
inline void readstr(char *s) {
  char ch;
  while ((ch = getchar()) == ' ' || ch == '\n')
    ;
  *(s++) = ch;
  while ((ch = getchar()) != ' ' && ch != '\n') *(s++) = ch;
  *s = '\0';
}
inline void writestr(const char *s) {
  while (*s != '\0') putchar(*(s++));
  putchar('\n');
}
inline long long readll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int debug = 0;
const int maxn = 1e5 + 10;
int p[maxn];
int c[maxn];
bool vis[maxn];
int main() {
  if (debug) freopen("in.txt", "r", stdin);
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) p[i] = readint();
    memset(vis, (0), sizeof(vis));
    int k = 0;
    int mini = int_inf, pointer = -1;
    bool odd = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      int j = i;
      c[k] = i;
      int sz = 1;
      while (p[j] != i) j = p[j], vis[j] = 1, ++sz;
      vis[i] = 1;
      if (sz < mini) mini = ((mini) < (sz) ? (mini) : (sz)), pointer = k;
      if (sz > 2 && (sz & 1)) odd = 1;
      k++;
    }
    if (mini > 2 || (mini > 1 && odd))
      puts("NO");
    else {
      puts("YES");
      if (mini == 1) {
        for (int i = 1; i <= n; i++) {
          if (i == c[pointer]) continue;
          printf("%d %d\n", c[pointer], i);
        }
      } else {
        printf("%d %d\n", c[pointer], p[c[pointer]]);
        for (int i = 0; i <= k - 1; i++) {
          if (i == pointer) continue;
          int j = c[i];
          int tem = c[pointer];
          printf("%d %d\n", tem, c[i]);
          while (p[j] != c[i])
            printf("%d %d\n", p[tem], p[j]), j = p[j], tem = p[tem];
        }
      }
    }
  }
  return 0;
}
