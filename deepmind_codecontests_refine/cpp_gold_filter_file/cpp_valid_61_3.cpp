#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
using namespace std;
void setup() {}
void work() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    int n, cnt = 0;
    scanf("%d", &n);
    char s[n + 5];
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) cnt += (s[i] != '?');
    for (int i = 1; i <= n; i++) cnt += (s[i] != '?');
    if (!cnt) s[1] = 'R';
    for (int i = 2; i <= n; i++)
      if (s[i] == '?' && s[i - 1] != '?') s[i] = s[i - 1] ^ ('B' ^ 'R');
    for (int i = n - 1; i; i--)
      if (s[i] == '?' && s[i + 1] != '?') s[i] = s[i + 1] ^ ('B' ^ 'R');
    printf("%s\n", s + 1);
  }
}
int main() {
  setup();
  work();
  return 0;
}
