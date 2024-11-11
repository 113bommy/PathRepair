#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ' || c == '\n')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, q, i, j, k, a[505][1005], num, mod = 1e9 + 7;
const int f[5] = {0, 1, 3, 2, 4};
int main() {
  read(n);
  read(m);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    for (((j)) = (1); ((j)) <= ((m)); ((j))++) {
      char c;
      readc(c);
      a[j][i] = c - 'a';
    }
  }
  read(q);
  for (((i)) = (1); ((i)) <= ((q)); ((i))++) {
    for (((j)) = (1); ((j)) <= ((m)); ((j))++) {
      char c;
      readc(c);
      a[j][i + n] = c - 'a';
    }
  }
  num = 1;
  int ans = 1;
  for (((j)) = (1); ((j)) <= ((n)); ((j))++) {
    for ((i) = (num + 1); (i) <= (m); (i)++) {
      if (a[i][j] > a[num][j]) {
        for (((k)) = (1); ((k)) <= ((n + q)); ((k))++) {
          swap(a[i][k], a[num][k]);
        }
      }
    }
    if (num > m || !a[num][j]) {
      ans = 5ll * ans % mod;
      continue;
    }
    for (k = n + q; k >= j; k--) {
      a[num][k] = a[num][k] * f[a[num][j]] % 5;
    }
    for (i = num + 1; i <= m; i++) {
      for (k = n + q; k >= j; k--) {
        a[i][k] = (a[i][k] + 4 * a[num][k] * a[i][j]) % 5;
      }
    }
    num++;
  }
  for (((i)) = (1); ((i)) <= ((q)); ((i))++) {
    int f = 1;
    for ((j) = (num); (j) <= (m); (j)++) {
      if (a[j][n + i]) {
        f = 0;
        break;
      }
    }
    if (f)
      cout << ans << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
