#include <bits/stdc++.h>
using namespace std;
const int INF = 10e9;
int main() {
  int n, m, i, j, a, b;
  while (scanf("%d %d %d %d %d %d", &n, &m, &i, &j, &a, &b) != EOF) {
    if ((i == 1 && j == 1) || (i == 1 && j == m) || (i == n && j == 1) ||
        (i == n && j == m)) {
      puts("0");
      continue;
    }
    if ((i - a < 1 && i + a > n) || (j - b < 1 && j + b > m)) {
      printf("Poor Inna and pony!\n");
      continue;
    }
    int ans = INF;
    if ((i - 1) % a == 0 && (j - 1) % b == 0 &&
        ((i - 1) / a) % 2 == ((j - 1) / b) % 2)
      ans = min(ans, max((i - 1) / a, (j - 1) / b));
    if ((i - 1) % a == 0 && (m - j) % b == 0 &&
        ((i - 1) / a) % 2 == ((m - j) / b) % 2)
      ans = min(ans, max((i - 1) / a, (m - j) / b));
    if ((n - i) % a == 0 && (j - 1) % b == 0 &&
        ((n - i) / a) % 2 == ((j - 1) / b) % 2)
      ans = min(ans, max((n - i) / a, (j - 1) / b));
    if ((n - i) % a == 0 && (m - j) % b == 0 &&
        ((n - i) / a) % 2 == ((m - j) / b) % 2)
      ans = min(ans, max((n - i) / a, (m - j) / b));
    if (ans == INF)
      puts("Poor Inna and pony!");
    else
      printf("%d\n", ans);
  }
  return 0;
}
