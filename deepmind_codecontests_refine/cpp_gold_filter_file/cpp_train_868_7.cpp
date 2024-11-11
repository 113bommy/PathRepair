#include <bits/stdc++.h>
using namespace std;
int yy, mm, dd, hh, mi, ss, x, y, n, m,
    mo[15] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, f[300003];
char in[5000008];
int main() {
  for (int i = 1; i <= 12; i++) mo[i] += mo[i - 1];
  x = 1, y = 1;
  scanf("%d %d", &n, &m);
  while (scanf("%d-%d-%d %d:%d:%d:", &yy, &mm, &dd, &hh, &mi, &ss) != EOF) {
    cin.getline(in, 5000001);
    f[x++] = ss + mi * 60 + hh * 3600 + dd * 86400 + mo[mm - 1] * 86400;
    while (f[x - 1] - f[y] >= n && x > y) y++;
    if ((x - y) >= m) {
      printf("2012-%02d-%02d %02d:%02d:%02d\n", mm, dd, hh, mi, ss);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
