#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n;
char a[maxn], b[maxn];
long long sum[3][maxn][30];
double x, y;
int main() {
  scanf("%d", &n);
  scanf("%s %s", a + 1, b + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      sum[1][i][j] = sum[1][i - 1][j];
      sum[2][i][j] = sum[2][i - 1][j];
    }
    int now = a[i] - 'A';
    sum[1][i][now] += i;
    now = b[i] - 'A';
    sum[2][i][now] += i;
  }
  for (int i = 1; i <= n; i++) {
    int now = b[i] - 'A';
    x += (1.0 * sum[1][i][now]) * (n - i + 1);
    now = a[i] - 'A';
    x += (1.0 * sum[2][i][now]) * (n - i + 1);
    if (a[i] == b[i]) {
      x -= (1.0 * i) * (n - i + 1);
    }
  }
  y = (1.0 + n) * n * (2.0 * n + 1) / 6.0;
  printf("%.10f\n", x / y);
  return 0;
}
