#include <bits/stdc++.h>
using namespace std;
long long V[9000000];
long long connection[3000][3000 / 64 + 1];
int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
  int cr = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      V[cr++] =
          ((y[j] - y[i]) * (y[j] - y[i]) + (x[j] - x[i]) * (x[j] - x[i])) *
              (4096LL * 4096LL) +
          i * 4096 + j;
  sort(V, V + cr);
  int res = 0;
  for (int i = cr - 1; i >= 0; i--) {
    int a = V[i] % (4096 * 4096) / 4096;
    int b = V[i] % 4096;
    connection[a][b / 64] |= 1LL << (b % 64);
    connection[b][a / 64] |= 1LL << (a % 64);
    int ok = 0;
    for (int j = 0; j < (n + 63) / 64; j++)
      if (connection[a][j] & connection[b][j]) {
        res = V[i] / 4096 / 4096;
        ok = 1;
      }
    if (ok) break;
  }
  printf("%.8f\n", sqrt(res) / 2.0);
  return 0;
}
