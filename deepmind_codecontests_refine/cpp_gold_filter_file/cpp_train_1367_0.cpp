#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char zf = 1;
  char ch = getchar();
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') zf = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * zf;
}
void write(long long y) {
  if (y < 0) putchar('-'), y = -y;
  if (y > 9) write(y / 10);
  putchar(y % 10 + 48);
}
void writeln(const long long y) {
  write(y);
  putchar('\n');
}
int k, m, n, x, y, z, cnt;
long long ans;
int cost[] = {0, 2, 3, 4, 6};
char c[100010];
long long a[100010];
long long dist[5];
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) a[i] = read();
  scanf("%s", c + 1);
  for (register int i = 1; i <= n; i++) {
    if (c[i] == 'G') {
      dist[2] += a[i] * 2;
      dist[4] = 100000000000000ll;
    }
    if (c[i] == 'W') {
      dist[1] += a[i] * 2;
      dist[3] = 100000000000000ll;
    }
    for (register int j = 1; j <= 4; j++) {
      long long jl = min((long long)a[i], dist[j]);
      ans += jl * cost[j];
      dist[j] -= jl;
      a[i] -= jl;
    }
  }
  cout << ans;
  return 0;
}
