#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  T w = 1;
  n = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    n = (n << 1) + (n << 3) + (ch ^ 48);
    ch = getchar();
  }
  n *= w;
}
template <typename T>
inline void write(T x) {
  unsigned long long y = 0;
  T l = 0;
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (!x) {
    putchar(48);
    return;
  }
  while (x) {
    y = y * 10 + x % 10;
    x /= 10;
    l++;
  }
  while (l) {
    putchar(y % 10 + 48);
    y /= 10;
    l--;
  }
}
template <typename T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <typename T>
inline void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T>
inline void checkmax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void checkmin(T &a, T b) {
  a = a < b ? a : b;
}
long long a[33][33];
int main() {
  int n;
  read(n);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) {
      if (i == 1 && j == 1) continue;
      if (i == n && j == n) continue;
      if (!(j & 1)) continue;
      a[i][j] = (1LL << (i + j - 2));
    }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (n - 1); j++) writes(a[i][j]);
    writeln(a[i][n]);
  }
  cout.flush();
  int q;
  read(q);
  while (q--) {
    int k;
    read(k);
    int posx = 1, posy = 1;
    writes(posx);
    writeln(posy);
    for (int i = (1); i <= (n * 2 - 3); i++) {
      if (posx + 1 > n)
        posy++;
      else if (posy + 1 > n)
        posx++;
      else if (a[posx + 1][posy] > 0 && (k & a[posx + 1][posy]))
        posx++;
      else if (a[posx][posy + 1] > 0 && (k & a[posx][posy + 1]))
        posy++;
      else if (!a[posx + 1][posy])
        posx++;
      else
        posy++;
      writes(posx);
      writeln(posy);
    }
    writes(n);
    writeln(n);
    cout.flush();
  }
  return 0;
}
