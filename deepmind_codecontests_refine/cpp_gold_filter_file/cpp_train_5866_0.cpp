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
  while (((c = getchar()) == ' ') || c == '\n')
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
double f[3005][3005], p[3005][3005], tmp[3005], dlt[3005], ans;
int n, m, i, j;
void resolve(int x) {
  int i;
  for ((i) = (0); (i) <= (n); (i)++) {
    tmp[i] = f[x][i];
  }
  f[x][0] = 0;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    f[x][i] = tmp[i - 1] * p[i][x] + f[x][i - 1] * (1 - p[i][x]);
  }
  dlt[x] -= f[x][n];
}
int main() {
  scanf("%d%d", &n, &m);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    for (((j)) = (1); ((j)) <= ((m)); ((j))++) {
      scanf("%lf", &p[i][j]);
      p[i][j] /= 1000.0;
    }
  }
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
    f[i][0] = 1;
    for (((j)) = (1); ((j)) <= ((n)); ((j))++) {
      f[i][j] = f[i][j - 1] * (1.0 - p[j][i]);
    }
    dlt[i] = 1.0 - f[i][n];
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    int k = 1;
    for (((j)) = (1); ((j)) <= ((m)); ((j))++) {
      if (dlt[j] > dlt[k]) {
        k = j;
      }
    }
    ans += dlt[k];
    resolve(k);
  }
  printf("%.10f\n", ans);
  return 0;
}
