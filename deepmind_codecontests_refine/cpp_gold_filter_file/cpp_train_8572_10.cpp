#include <bits/stdc++.h>
using namespace std;
int split(int s, int x, int y) {
  int i, cnt = 0;
  ;
  for (i = 1; i <= x; i++)
    if (s % i == 0 && s / i <= y) cnt++;
  return cnt;
}
int main() {
  int n, m, i, j, s;
  long long sum = 0;
  scanf("%d%d%d", &n, &m, &s);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      if (i % 2 == 0 || j % 2 == 0) continue;
      if (i * j == s)
        sum += (long long)(n - i + 1) * (m - j + 1) *
               (2 * (i / 2 + 1) * (j / 2 + 1) - 1);
      else if (i * j >= s && i + j - 1 <= s && (i * j - s) % 4 == 0)
        sum += (long long)split((i * j - s) / 4, i / 2, j / 2) * (n - i + 1) *
               (m - j + 1) * 2;
    }
  cout << sum;
  return 0;
}
