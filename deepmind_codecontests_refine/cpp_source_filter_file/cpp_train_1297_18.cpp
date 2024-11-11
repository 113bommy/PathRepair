#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0, b = getchar(), c = 1;
  while (!isdigit(b)) c = b == '-' ? -1 : 1, b = getchar();
  while (isdigit(b)) a = a * 10 + b - '0', b = getchar();
  return a * c;
}
long long n, m, a[1 << 21];
double dp[1 << 21];
string b[50];
int main() {
  n = read();
  for (int i = 0; i < n; i++) cin >> b[i];
  m = b[0].size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int x = 0;
      for (int k = 0; k < m; k++)
        if (b[i][k] == b[j][k]) x |= 1 << k;
      a[x] |= (1 << i | 1 << j);
    }
  for (int i = (1 << m) - 1; i >= 0; i--) {
    int x = 0;
    for (int j = 0; j < m; j++)
      if ((i >> j) & 1) a[i ^ (1 << j)] |= a[i];
    for (int j = 0; j < m; j++)
      if (!((i >> j) & 1)) {
        x++;
        dp[i] += dp[i | (1 << j)];
      }
    if (x == 0) continue;
    dp[i] /= x;
    x = 0;
    for (int j = 0; j < n; j++)
      if (((a[i] >> j) & 1)) x++;
    dp[i] += (double)x / n;
  }
  printf("%0.15lf", dp[0]);
  return 0;
}
