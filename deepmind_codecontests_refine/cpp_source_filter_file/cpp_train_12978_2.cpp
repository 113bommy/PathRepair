#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
bool Finish_read;
template <class T>
inline void read(T &x) {
  Finish_read = 0;
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    if (ch == EOF) return;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
  Finish_read = 1;
}
template <class T>
inline void print(T x) {
  if (x / 10 != 0) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar('\n');
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar(' ');
}
int a[5005][5005] = {0}, ans[5005][5005] = {0};
void init(int n) {
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= i; j++) a[i][j] = a[i - 1][j - 1] ^ a[i][j - 1];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) ans[i][j] = a[j][j - i + 1];
  for (int i = n; i >= 1; i--)
    for (int j = i + 1; j <= n; j++) {
      int tmp = max(ans[i][j], ans[i + 1][j]);
      tmp = max(tmp, ans[i][j - 1]);
      ans[i][j] = max(ans[i][j], tmp);
    }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i][1]);
  int T;
  init(n);
  scanf("%d", &T);
  while (T--) {
    int p, q;
    scanf("%d%d", &p, &q);
    printf("%d\n", ans[p][q]);
  }
  return 0;
}
