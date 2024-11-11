#include <bits/stdc++.h>
using namespace std;
int n, k, ans, f[100001];
int read() {
  int pos = 1, num = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') pos = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = num * 10 + (int)(ch - '0');
    ch = getchar();
  }
  return pos * num;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writesp(int x) {
  write(x);
  putchar(' ');
}
void writeln(int x) {
  write(x);
  putchar('\n');
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= k; i++) {
    int x = read(), y = read();
    int fx = find(x), fy = find(y);
    if (fx != fy)
      f[fx] = f[fy];
    else
      ans++;
  }
  writeln(ans);
}
