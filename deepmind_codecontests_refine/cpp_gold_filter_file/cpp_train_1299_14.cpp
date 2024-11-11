#include <bits/stdc++.h>
using namespace std;
int r[1000 + 10], c[1000 + 10];
int main() {
  char s[1000 + 10][1000 + 10];
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*') {
        r[i]++;
        c[j]++;
      }
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        sum += (r[i] - 1) * (c[j] - 1);
      }
    }
  }
  printf("%lld\n", sum);
  return 0;
}
